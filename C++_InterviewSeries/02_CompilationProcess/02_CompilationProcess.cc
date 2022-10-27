#include<iostream>
using namespace std;
#define ADD(x, y) x+y

int main() {
    cout << "I Love C++" << endl;
    cout << ADD(1, 2) << endl;
    return 0;
}

// compile using g++ 02_CompilationProcess.cc --save-temps
// it will generate all intermediate files of compilation process.

/////////////  Diagram 1 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

[Source Code] ---> Compiler ----> [Object Code] --*
                                                  |
[Source Code] ---> Compiler ----> [Object Code] --*--> Linker --> [Executable] ---> Loader (Part of OS)..load executable into memory
                                                  |                                    |
                                  [Library File]--*                                    |
                                                                                       |
                                                                                       |
                                                                                       v
                                                                        [Running Executable in Memory]
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////  Diagram 2////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
                        Editor of IDE (write source code)
                                |
                                | (.cpp, .h) source code, header file
                                |
                                v
                            Processor
                                |
                                | (*.i) Included files, Replaced Symbols(replace macro fields)
                                |
                                v
                            Compiler (has all analzers i.e. lexical, syntacticm, semantic etc)
                                | first it converts into AST(Abstract Syntax Tree) to derive meaning of the code.
                                | (*.s) assembly code
                                |
                                v
                            Assembler
                                |
                                | (*.o) Object Code
                                |
                                v
Static Libraries (.lib, .a)-> Linker
                                |
                                | (.exe) 
                                |
                                v
Dynamic Libraries(.dll, .so)-> Loader
                                |
                                |
                                |
                                v
                        Operating System
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////