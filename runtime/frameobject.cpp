//
// Created by Bochao An on 2022/12/26.
//

#include "frameobject.h"

FrameObject::FrameObject(CodeObject *codes) {
    _consts = codes->_consts;
    _names = codes->_names;

    _locals = new Map<HiObject*, HiObject*>();
    _stack = new ArrayList<HiObject*>();
    _loop_stack = new ArrayList<Block*>();

    _codes = codes;
    _pc = 0;
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