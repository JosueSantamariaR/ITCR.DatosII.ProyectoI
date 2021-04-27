
#include "FuncDefinition.h"
#include <iostream>

namespace interpreter{
    using namespace std;


    void FuncDefinition::debugPrint() const {
        cout << mName << "(\n";

        for (ParameterDefinition param : mParameters) {
            param.debugPrint(1);
        }

        cout << ") {\n";
        for (Declarations declaration : mStatements) {
            declaration.debugPrint(0);
        }
        cout << "}" << endl;
    }

    void ParameterDefinition::debugPrint(size_t indent) const {
        cout << string(indent, '\t') << mType.mName << " " << mName << endl;
    }
}
