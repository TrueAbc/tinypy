//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_CODEOBJECT_H
#define TINYPY_CODEOBJECT_H
#include "object/HiObject.h"
#include "object/HiString.h"
#include "util/ArrayList.h"

class CodeObject : public HiObject{
public:
    int _argcount; // 参数个数
    int _nlocals; // 局部变量个数
    int _stack_size; // 这段code的操作数栈的最大深度
    int _flag; // 属性值, 固定0x40

    HiString* _bytecodes; // 字节码
    ArrayList<HiObject*>* _consts; // 常量表
    ArrayList<HiObject*>* _names; // 变量表
    ArrayList<HiObject*>* _var_names; // 参数列表, 函数或者方法的输入参数

    ArrayList<HiObject*>* _cell_vars; // 用于闭包
    ArrayList<HiObject*>* _free_vars;

    HiString* _file_name; // 文件名
    HiString* _co_name; // code所属模块

    int _lineno; //
    HiString* _notable; // line number table, 用于traceback的调用栈

    CodeObject(int argcount, int nlocals, int stacksize, int flag, HiString* bytecodes,
               ArrayList<HiObject*>* consts, ArrayList<HiObject*>* names,
               ArrayList<HiObject*>* varnames,
               ArrayList<HiObject*>* freevars, ArrayList<HiObject*>* cellvars,
               HiString* file_name, HiString* co_name, int lineno, HiString* notable);

};


#endif //TINYPY_CODEOBJECT_H
