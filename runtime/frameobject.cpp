//
// Created by Bochao An on 2022/12/26.
//

#include "frameobject.h"
#include "funtionobject.h"

// 函数调用使用
FrameObject::FrameObject(FunctionObject *func, ObjList args) {
    _codes = func->_func_code;
    _consts = _codes->_consts;
    _names = _codes->_names;

    _locals = new Map<HiObject*, HiObject*>();
    _globals = func->globals();

    _stack = new ArrayList<HiObject*>();
    _loop_stack = new ArrayList<Block*>();
    _fast_locals = new ArrayList<HiObject*>(); // 函数的参数

    if (func->_defaults) {
        int dft_cnt = func->defaults()->size();
        int argcnt = _codes->_argcount;
        while (dft_cnt--){
            _fast_locals->set(--argcnt, func->_defaults->get(dft_cnt));
        }
    }

    if (args) {
        for (int i = 0; i < args->size(); ++i) {
            _fast_locals->set(i, args->get(i));
        }
    }

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