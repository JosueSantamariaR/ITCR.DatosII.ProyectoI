/**
  * @file Declarations.cpp
  * */
#include <iostream>
#include "Declarations.h"

namespace interpreter{

/**
 * @brief Metodo encargado imprimir las declaraciones
 * @param size_t indent
 * @authors Akion&Josue
 */
void Declarations::debugPrint(size_t indent) {
    cout << string(indent, '\t') << sStatementKindStrings[int(mKind)] << " ";
    cout << mType.mName << " " << mName << " (\n";
    for (Declarations declaration : mParameters) {
        declaration.debugPrint(indent + 1);
    }
    cout << string(indent, '\t') << ")" << endl;
}

}
