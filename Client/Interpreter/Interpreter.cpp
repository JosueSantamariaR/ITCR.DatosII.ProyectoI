//
// Created by garroakion on 19/4/2021.
//

#include "Interpreter.h"
#include <iostream>
#include "./optional.h"
namespace interpreter{
    using namespace std;

    struct OperatorEntry {
        string mName;
        size_t mPrecedence;
    };

    static map<string, OperatorEntry> sOperators{
            // precedence 0 is reserved for "no operator".
            {"+", OperatorEntry{"+", 1}},
            {"-", OperatorEntry{"-", 1}},
            {"/", OperatorEntry{"/", 10}},
            {"*", OperatorEntry{"*", 10}}
    };

    bool Interpreter::expectFunctionDefinition() {
        vector<Token>::iterator parseStart = mCurrentToken;
        std::experimental::optional<VarTypes> possibleType = expectType();
        if (possibleType.operator bool()) { // We have a type!
            std::experimental::optional<Token> possibleName = expectIdentifier();

            if (possibleName.operator bool()) { // We have a name!
                std::experimental::optional<Token> possibleOperator = expectOperator("(");

                if (possibleOperator.operator bool()) { // We have a function!

                    FuncDefinition func;
                    func.mName = possibleName->mText;

                    while(!expectOperator(")").operator bool()) {
                        std::experimental::optional<VarTypes> possibleParamType = expectType();
                        if (!possibleParamType.operator bool()) {
                            throw runtime_error("Expected a type at start of argument list.");
                        }
                        std::experimental::optional<Token> possibleVariableName = expectIdentifier();

                        ParameterDefinition param;
                        param.mType = possibleParamType->mName;
                        if (possibleVariableName.operator bool()) {
                            param.mName = possibleVariableName->mText;
                        }
                        func.mParameters.push_back(param);

                        if (expectOperator(")").operator bool()) {
                            break;
                        }
                        if (!expectOperator(",").operator bool()) {
                            throw runtime_error("Expected ',' to separate parameters or ')' to indicate end of argument list.");
                        }
                    }

                    std::experimental::optional<vector<Declarations>> statements = parseFunctionBody();
                    if (!statements.operator bool()) {
                        mCurrentToken = parseStart;
                        return false;
                    }
                    func.mStatements.insert(func.mStatements.begin(), statements->begin(), statements->end());

                    mFunctions[func.mName] = func;

                    return true;
                } else {
                    mCurrentToken = parseStart;
                }
            } else {
                mCurrentToken = parseStart;
            }
        }
        return false;
    }

    void Interpreter::parse(vector<Token> &tokens) {
        mEndToken = tokens.end();
        mCurrentToken = tokens.begin();

        while(mCurrentToken != mEndToken) {
            if (expectFunctionDefinition()) {

            } else {
                cerr << "Unknown identifier " << mCurrentToken->mText << "." << endl;
                ++mCurrentToken;
            }
        }
    }

    std::experimental::optional<Token> Interpreter::expectIdentifier(const string &name) {
        if (mCurrentToken == mEndToken) { return std::experimental::nullopt; }
        if (mCurrentToken->mType != IDENTIFIER) { return std::experimental::nullopt; }
        if (!name.empty() && mCurrentToken->mText != name) { return std::experimental::nullopt; }

        Token returnToken = *mCurrentToken;
        ++mCurrentToken;
        return returnToken;
    }

    std::experimental::optional<Token> Interpreter::expectOperator(const string &name) {
        if (mCurrentToken == mEndToken) { return std::experimental::nullopt; }
        if (mCurrentToken->mType != OPERATOR) { return std::experimental::nullopt; }
        if (!name.empty() && mCurrentToken->mText != name) { return std::experimental::nullopt; }

        Token returnToken = *mCurrentToken;
        ++mCurrentToken;
        return returnToken;
    }

    Interpreter::Interpreter() {
        mTypes["void"] = VarTypes("void", VOID);
        mTypes["int"] = VarTypes("signed int", INT32);
        mTypes["unsigned"] = VarTypes("unsigned int", UINT32);
        mTypes["char"] = VarTypes("signed char", INT8);
        mTypes["uint8_t"] = VarTypes("uint8_t", INT8);
        mTypes["double"] = VarTypes("double", DOUBLE);
    }

    std::experimental::optional<VarTypes> Interpreter::expectType() {
        std::experimental::optional<Token> possibleType = expectIdentifier();
        if (!possibleType) { return std::experimental::nullopt; }

        map<string, VarTypes>::iterator foundType = mTypes.find(possibleType->mText);
        if (foundType == mTypes.end()) {
            --mCurrentToken;
            return std::experimental::nullopt;
        }

        return foundType->second;
    }

    std::experimental::optional<vector<Declarations>> Interpreter::parseFunctionBody() {
        if (!expectOperator("{").operator bool()) {
            return std::experimental::nullopt;
        }

        vector<Declarations> statements;

        while(!expectOperator("}").operator bool()) {
            std::experimental::optional<Declarations> statement = expectStatement();
            if (statement.operator bool()) {
                statements.push_back(statement.value());
            }

            if (!expectOperator(";").operator bool()) {
                throw runtime_error("Expected ';' at end of statement.");
            }
        }

        return statements;
    }

    string Interpreter::debugPrint() const {

        for (auto funcPair : mFunctions) {
              funcPair.second.debugPrint();
        }
        return 0;

    }

    std::experimental::optional<Declarations> Interpreter::expectOneValue() {
        std::experimental::optional<Declarations> result;
        if (mCurrentToken != mEndToken && mCurrentToken->mType == DOUBLE_LITERAL) {
            Declarations doubleLiteralStatement;
            doubleLiteralStatement.mKind = StatementKind::LITERAL;
            doubleLiteralStatement.mName = mCurrentToken->mText;
            doubleLiteralStatement.mType = VarTypes("double", DOUBLE);
            result = doubleLiteralStatement;
            ++mCurrentToken;
        } else if (mCurrentToken != mEndToken && mCurrentToken->mType == INTEGER_LITERAL) {
            Declarations integerLiteralStatement;
            integerLiteralStatement.mKind = StatementKind::LITERAL;
            integerLiteralStatement.mName = mCurrentToken->mText;
            integerLiteralStatement.mType = VarTypes("signed integer", INT32);
            result = integerLiteralStatement;
            ++mCurrentToken;
        } else if (mCurrentToken != mEndToken && mCurrentToken->mType == STRING_LITERAL) {
            Declarations stringLiteralStatement;
            stringLiteralStatement.mKind = StatementKind::LITERAL;
            stringLiteralStatement.mName = mCurrentToken->mText;
            stringLiteralStatement.mType = VarTypes("string", UINT8);
            result = stringLiteralStatement;
            ++mCurrentToken;
        } else if (expectOperator("(").operator bool()) {
            result = expectExpression();
            if (!expectOperator(")").operator bool()) {
                throw runtime_error("Unbalanced '(' in parenthesized expression.");
            }
        }
        if (!result.operator bool()) {
            result = expectFunctionCall();
        }
        return result;
    }

    std::experimental::optional<Declarations> Interpreter::expectVariableDeclaration() {
        vector<Token>::iterator startToken = mCurrentToken;
        std::experimental::optional<VarTypes> possibleType = expectType();
        if (!possibleType.operator bool()) {
            mCurrentToken = startToken;
            return std::experimental::nullopt;
        }

        std::experimental::optional<Token> possibleVariableName = expectIdentifier();
        if (!possibleType.operator bool()) {
            mCurrentToken = startToken;
            return std::experimental::nullopt;
        }

        Declarations declaration;

        declaration.mKind = StatementKind::VARIABLE_DECLARATION;
        declaration.mName = possibleVariableName->mText;
        declaration.mType = possibleType.value();

        if (expectOperator("=").operator bool()) {
            std::experimental::optional<Declarations> initialValue = expectExpression();
            if (!initialValue.operator bool()) {
                throw runtime_error("Expected initial value to right of '=' in variable declaration.");
            }

            declaration.mParameters.push_back(initialValue.value());
        }

        return declaration;
    }

    std::experimental::optional<Declarations> Interpreter::expectFunctionCall() {
        vector<Token>::iterator startToken = mCurrentToken;

        std::experimental::optional<Token> possibleFunctionName = expectIdentifier();
        if (!possibleFunctionName.operator bool()) {
            mCurrentToken = startToken;
            return std::experimental::nullopt;
        }

        if (!expectOperator("(").operator bool()) {
            mCurrentToken = startToken;
            return std::experimental::nullopt;
        }

        Declarations functionCall;
        functionCall.mKind = StatementKind::FUNCTION_CALL;
        functionCall.mName = possibleFunctionName->mText;

        while(!expectOperator(")").operator bool()) {
            std::experimental::optional<Declarations> parameter = expectExpression();
            if (!parameter.operator bool()) {
                throw runtime_error("Expected expression as parameter.");
            }
            functionCall.mParameters.push_back(parameter.value());

            if (expectOperator(")").operator bool()) {
                break;
            }
            if (!expectOperator(",").operator bool()) {
                // TODO: Check whether we still have a current token.
                throw runtime_error(string("Expected ',' to separate parameters, found '") + mCurrentToken->mText + "'.");
            }
        }

        return functionCall;
    }

    std::experimental::optional<Declarations> Interpreter::expectStatement() {
        std::experimental::optional<Declarations> result = expectExpression();
        if (!result.operator bool()) {
            result = expectVariableDeclaration();
        }
        return result;
    }

    std::experimental::optional<Declarations> Interpreter::expectExpression() {
        std::experimental::optional<Declarations> lhs = expectOneValue();
        if (!lhs.operator bool()) { return std::experimental::nullopt; }

        while (true) {
            std::experimental::optional<Token> op = expectOperator();
            if (!op.operator bool()) { break; }
            int rhsPrecedence = operatorPrecedence(op->mText);
            if (rhsPrecedence == 0) {
                --mCurrentToken;
                return lhs;
            }
            std::experimental::optional<Declarations> rhs = expectOneValue();
            if (!rhs.operator bool()) {
                --mCurrentToken;
                return lhs;
            }

            Declarations * rightmostStatement = findRightmostStatement(&lhs.value(), rhsPrecedence);
            if (rightmostStatement) {
                Declarations operatorCall;
                operatorCall.mKind = StatementKind::OPERATOR_CALL;
                operatorCall.mName = op->mText;
                operatorCall.mParameters.push_back(rightmostStatement->mParameters.at(1));
                operatorCall.mParameters.push_back(rhs.value());
                rightmostStatement->mParameters[1] = operatorCall;
            } else {
                Declarations operatorCall;
                operatorCall.mKind = StatementKind::OPERATOR_CALL;
                operatorCall.mName = op->mText;
                operatorCall.mParameters.push_back(lhs.value());
                operatorCall.mParameters.push_back(rhs.value());
                lhs = operatorCall;
            }
        }

        return lhs;
    }

    Declarations * Interpreter::findRightmostStatement(Declarations *lhs, size_t rhsPrecedence) {
        if (lhs->mKind != StatementKind::OPERATOR_CALL) { return nullptr; }
        if (operatorPrecedence(lhs->mName) >= rhsPrecedence) { return nullptr; }

        Declarations * rhs = &lhs->mParameters.at(1);
        rhs = findRightmostStatement(rhs, rhsPrecedence);
        if (rhs == nullptr) { return lhs; }
        return rhs;
    }


    size_t Interpreter::operatorPrecedence(const string &operatorName) {
        map<string, OperatorEntry>::iterator foundOperator = sOperators.find(operatorName);
        if (foundOperator == sOperators.end()) {
            return 0;
        }
        return foundOperator->second.mPrecedence;
    }
}
