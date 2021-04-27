#include "memoryblock.h"

const string &MemoryBlock::getName() const {
    return this->name;

}

void MemoryBlock::setName(const string &name) {
    MemoryBlock::name = name;
}

int MemoryBlock::getMemoryvalue() const {
    return this->memoryvalue;
}

void MemoryBlock::setMemoryvalue(int memoryvalue) {
    MemoryBlock::memoryvalue = memoryvalue;
}

const string &MemoryBlock::getValue() const {
    return this->value;
}

void MemoryBlock::setValue(const string &value) {
    MemoryBlock::value = value;
}

MemoryBlock::MemoryBlock( string name, int memoryvalue, string value)  {
    this->name = name;
    this->memoryvalue = memoryvalue;
    this->value= value;

}
