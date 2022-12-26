//
// Created by Bochao An on 2022/12/26.
//

#include "frameobject.h"
#include "funtionobject.h"

// 函数调用使用
FrameObject::FrameObject(FunctionObject *func) {
    _codes = func->_func_code;
    _consts = _codes->_consts;
    _names = _codes->_names;

    _locals = new Map<HiObject*, HiObject*>();
    _globals = func->globals();
    _stack = new ArrayList<HiObject*>();
    _loop_stack = new ArrayList<Block*>();

    _pc = 0;
    _sender = nullptr;
}


// 用于module的构造, 也就是构造第一个frame
FrameObject::FrameObject(CodeObject *codes) {
    _consts = codes->_consts;
    _names = codes->_names;

    _locals = new Map<HiObject*, HiObject*>();
    _globals = _locals;
    _stack = new ArrayList<HiObject*>();
    _loop_stack = new ArrayList<Block*>();

    _codes = codes;
    _pc = 0;
    _sender = nullptr;
}

int FrameObject::get_op_arg() {
    int byte1 = _codes->_bytecodes->value()[_pc++] & 0xff;
    int byte2 = _codes->_bytecodes->value()[_pc++] & 0xff;
    return byte2 << 8 | byte1;
}

unsigned char FrameObject::get_op_code() {
    return _codes->_bytecodes->value()[_pc++];
}

bool FrameObject::has_more_codes() {
    return _pc < _codes->_bytecodes->length();
}