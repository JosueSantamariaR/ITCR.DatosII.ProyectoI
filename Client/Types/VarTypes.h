#pragma once

#include <string>
#include <vector>

namespace interpreter{
    using namespace std;
    enum BUILTIN_TYPE {
        VOID,
        INT8,
        UINT8,
        INT32,
        UINT32,
        DOUBLE,
        STRUCT
    };
    class VarTypes {
    public:
        VarTypes(const string &name = "", enum BUILTIN_TYPE type = VOID)
                : mName(name), mType(type) {}

        string mName;
        enum BUILTIN_TYPE mType;
        vector<VarTypes> mFields; // for STRUCT only.
    };

    };





