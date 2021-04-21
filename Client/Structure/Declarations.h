
#pragma once

#include <string>
#include <vector>
#include "../Types/VarTypes.h"


namespace interpreter{
    using namespace std;

    enum class StatementKind: int {
        VARIABLE_DECLARATION,
        FUNCTION_CALL,
        LITERAL,
        OPERATOR_CALL
    };
    static const char* sStatementKindStrings[] = {
            "VARIABLE_DECLARATION",
            "FUNCTION_CALL",
            "LITERAL",
            "OPERATOR_CALL"
    };
    class Declarations {
    public:
        string mName;
        VarTypes mType{VarTypes("void", VOID)};
        vector<Declarations> mParameters;
        StatementKind mKind{StatementKind::FUNCTION_CALL};

        void debugPrint(size_t indent);
    };

    }






