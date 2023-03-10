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
    Map<HiObject*, HiObject*>* _builtins;

    void run(CodeObject* code);

    Interpreter();

    ~Interpreter(){
        Universe::destroy();
    }

    void build_frame(HiObject* callable, ObjList args);
    void eval_frame();
    void leave_frame();
    void destroy_frame();
};


#endif //TINYPY_INTERPRETER_H
