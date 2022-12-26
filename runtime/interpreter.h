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
    HiObject* _ret_value;

    void run(CodeObject* code);

    Interpreter(){
        Universe::genesis();
    }

    ~Interpreter(){
        Universe::destroy();
    }

    void build_frame(HiObject* callable);
    void eval_frame();
    void leave_frame();
    void destroy_frame();
};


#endif //TINYPY_INTERPRETER_H
