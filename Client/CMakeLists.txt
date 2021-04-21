cmake_minimum_required(VERSION 3.17)
project(CInterpreter)

set(CMAKE_CXX_STANDARD 14)



add_executable(CInterpreter main.cpp Interpreter/Interpreter.cpp Interpreter/Interpreter.h Types/VarTypes.cpp Types/VarTypes.h Tokens/Tokenizer.cpp Tokens/Tokenizer.h Structure/Declarations.cpp Structure/Declarations.h Structure/FuncDefinition.cpp Structure/FuncDefinition.h)