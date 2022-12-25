//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_INTERPRETER_H
#define TINYPY_INTERPRETER_H

#include "code/CodeObject.h"
#include "code/bytecode.h"
#include "object/HiInteger.h"
#include "util/map.h"
#include "universe.h"
#include "loopblock.h"

class Interpreter {
public:
    ArrayList<HiObject*>* _stack;
    ArrayList<HiObject*>* _consts;
    Map<HiObject*, HiObject*> _names; // 变量表
    ArrayList<Block*>* _loop_stack; // while循环记录while块


    void run(CodeObject* code);

    Interpreter(){
        Universe::genesis();
    }

    ~Interpreter(){
        Universe::destroy();
    }
};


#endif //TINYPY_INTERPRETER_H
