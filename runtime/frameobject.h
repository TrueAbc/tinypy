//
// Created by Bochao An on 2022/12/26.
//

#ifndef TINYPY_FRAMEOBJECT_H
#define TINYPY_FRAMEOBJECT_H

#include "code/CodeObject.h"
#include "loopblock.h"
#include "util/map.h"

class FunctionObject;
// 函数执行期间的活动记录
class FrameObject {
public:
    FrameObject(CodeObject* codes);
    FrameObject(FunctionObject* functionObject);
    ~FrameObject(){};

    ArrayList<HiObject*>* _stack;
    ArrayList<Block*>* _loop_stack;

    ArrayList<HiObject*>* _consts;
    ArrayList<HiObject*>* _names;

    Map<HiObject*, HiObject*>* _locals;
    Map<HiObject*, HiObject*>* _globals;

    CodeObject* _codes;
    int _pc;
    FrameObject* _sender; // 函数的调用链

public:

    void set_sender(FrameObject* x) {_sender = x;}
    FrameObject* sender(){return _sender;}

    void set_pc(int x){_pc = x;}
    int get_pc(){return _pc;}

    ArrayList<HiObject*>* stack() {return _stack;}
    ArrayList<Block*>* loop_stack(){return _loop_stack;}
    ArrayList<HiObject*>* consts() {return _consts;}
    ArrayList<HiObject*>* names() {return _names;}
    Map<HiObject*, HiObject*>* locals() {return _locals;}
    Map<HiObject*, HiObject*>* globals() {return _globals;}

    bool has_more_codes();
    unsigned char get_op_code();
    int get_op_arg();
    bool is_first_frame() {return _sender == nullptr;}
};


#endif //TINYPY_FRAMEOBJECT_H
