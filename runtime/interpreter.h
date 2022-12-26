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

class FrameObject;

class Interpreter {
public:
    FrameObject* _frame;

    void run(CodeObject* code);

    Interpreter(){
        Universe::genesis();
    }

    ~Interpreter(){
        Universe::destroy();
    }
};


#endif //TINYPY_INTERPRETER_H
