//
// Created by Bochao An on 2022/12/26.
//

#ifndef TINYPY_FRAMEOBJECT_H
#define TINYPY_FRAMEOBJECT_H

#include "code/CodeObject.h"
#include "loopblock.h"
#include "util/map.h"

// 函数执行期间的活动记录
class FrameObject {
public:
    FrameObject(CodeObject* codes);
    ~FrameObject();

    ArrayList<HiObject*>* _stack;
    ArrayList<Block*>* _loop_stack;

    ArrayList<HiObject*>* _consts;
    ArrayList<HiObject*>* _names;

    Map<HiObject*, HiObject*>* _locals;

    CodeObject* _codes;
    int _pc;

public:
    void set_pc(int x){_pc = x;}
    int get_pc(){return _pc;}

    ArrayList<HiObject*>* stack() {return _stack;}
    ArrayList<Block*>* loop_stack(){return _loop_stack;}
    ArrayList<HiObject*>* consts() {return _consts;}
    ArrayList<HiObject*>* names() {return _names;}
    Map<HiObject*, HiObject*>* locals() {return _locals;}

    bool has_more_codes();
    unsigned char get_op_code();
    int get_op_arg();
};


#endif //TINYPY_FRAMEOBJECT_H
