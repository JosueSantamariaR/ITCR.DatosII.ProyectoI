#include "memoryblock.h"



/**
 * @brief Constructor
 * @param string name
 * @param int memoryValue
 * @param string value
 * @authors Akion&Josue
 */
MemoryBlock::MemoryBlock( string name, int memoryvalue, string value)  {
    this->name = name;
    this->memoryvalue = memoryvalue;
    this->value= value;

}



/**
 * @brief Metodo que se encarga de obtener el nombre
 * @authors Akion&Josue
 */
const string &MemoryBlock::getName() const {
    return this->name;

}


/**
 * @brief Metodo que se encarga de establecer el nombre
 * @param string nombre
 * @authors Akion&Josue
 */
void MemoryBlock::setName(const string &name) {
    MemoryBlock::name = name;
}


/**
 * @brief Metodo que se encarga de obtener el valor de la memoria
 * @authors Akion&Josue
 */
int MemoryBlock::getMemoryvalue() const {
    return this->memoryvalue;
}


/**
 * @brief Metodo que se encarga de establecer el valor de la memoria
 * @param int value
 * @authors Akion&Josue
 */
void MemoryBlock::setMemoryvalue(int memoryvalue) {
    MemoryBlock::memoryvalue = memoryvalue;
}

/**
 * @brief Metodo que se encarga de obtner el valor de la variable
 * @param int value
 * @authors Akion&Josue
 */
const string &MemoryBlock::getValue() const {
    return this->value;
}

/**
 * @brief Metodo que se encarga de establecer el valor de la variable
 * @param string value
 * @authors Akion&Josue
 */
void MemoryBlock::setValue(const string &value) {
    MemoryBlock::value = value;
}



