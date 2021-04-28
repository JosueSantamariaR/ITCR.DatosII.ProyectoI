/**
  * @file memoryblock.h
  * */
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class MemoryBlock
{

private:

    string name;
    int memoryvalue;
    string value;

public:
    const string &getName() const;

    void setName(const string &name);

    int getMemoryvalue() const;

    void setMemoryvalue(int memoryvalue);

    const string &getValue() const;

    void setValue(const string &value);

public:

    MemoryBlock(string name, int memoryvalue, string value);

};

