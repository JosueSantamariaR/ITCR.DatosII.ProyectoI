
#include <iostream>
#include "Declarations.h"

namespace interpreter{
    void Declarations::debugPrint(size_t indent) {
        cout << string(indent, '\t') << sStatementKindStrings[int(mKind)] << " ";
        cout << mType.mName << " " << mName << " (\n";
        for (Declarations declaration : mParameters) {
            declaration.debugPrint(indent + 1);
        }
        cout << string(indent, '\t') << ")" << endl;
    }

}