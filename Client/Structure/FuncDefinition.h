#pragma once

#include "../Types/VarTypes.h"
#include "Declarations.h"
#include <string>
#include <vector>
namespace interpreter{
    using namespace std;

    class ParameterDefinition {
    public:
        string mName; // Empty string means no name given.
        VarTypes mType;

        void debugPrint(size_t indent) const;
    };
    class FuncDefinition {
    public:
        string mName;
        vector<ParameterDefinition> mParameters;
        vector<Declarations> mStatements;

        void debugPrint() const;
    };

}




