
#include "FuncDefinition.h"
#include <iostream>

namespace interpreter{
using namespace std;


/**
 * @brief Metodo encargado imprimir la defincion de las funciones
 * @authors Akion&Josue
 */

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

/**
 * @brief Metodo encargado imprimir la defincion de los parametros.
 * @param size_t indent
 * @authors Akion&Josue
 */
void ParameterDefinition::debugPrint(size_t indent) const {
    cout << string(indent, '\t') << mType.mName << " " << mName << endl;
}
}
