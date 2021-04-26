#pragma once

#include "../Tokens/Tokenizer.h"
#include "../Types/VarTypes.h"
#include "../Structure/FuncDefinition.h"
#include "../Structure/Declarations.h"


#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "./optional.h"


namespace interpreter {

    using namespace std;
    class Interpreter {
    public:
        Interpreter();
        static string applog;

        void parse(vector<Token> &tokens);

        void debugPrint() const;

    private:

        std::experimental::optional<VarTypes> expectType();

        //! Empty string means match any identifier.
        std::experimental::optional<Token> expectIdentifier(const string& name = string());

        //! Empty string means match any operator.
        std::experimental::optional<Token> expectOperator(const string& name = string());

        bool expectFunctionDefinition();

        vector<Token>::iterator mCurrentToken;
        vector<Token>::iterator mEndToken;
        map<string, VarTypes> mTypes;
        map<string, FuncDefinition> mFunctions;

        std::experimental::optional<vector<Declarations>> parseFunctionBody();

        std::experimental::optional<Declarations> expectOneValue();

        std::experimental::optional<Declarations> expectStatement();

        std::experimental::optional<Declarations> expectVariableDeclaration();

        std::experimental::optional<Declarations> expectFunctionCall();

        std::experimental::optional <Declarations> expectExpression();

        size_t operatorPrecedence(const string &operatorName);

        Declarations *findRightmostStatement(Declarations *lhs, size_t rhsPrecedence);
    };



}




