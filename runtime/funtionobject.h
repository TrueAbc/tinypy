//
// Created by Bochao An on 2022/12/26.
//

#ifndef TINYPY_FUNTIONOBJECT_H
#define TINYPY_FUNTIONOBJECT_H

#include "object/Klass.h"
#include "frameobject.h"

class FunctionKlass : public Klass {
private:
    FunctionKlass();
    static FunctionKlass* instance;

public:
    static FunctionKlass* get_instance();
    virtual void print(HiObject* obj);
};

// 其他类可以直接访问当前类的private和protected
class FunctionObject : public HiObject {
    friend class FunctionKlass;
    friend class FrameObject;

private:
    CodeObject* _func_code;
    HiString* _func_name;
    ObjList _defaults;

    unsigned int _flags;
    Map<HiObject*, HiObject*>* _globals;// 函数创建时候会绑定上下文的全局变量

public:
    FunctionObject(HiObject* code_object);
    FunctionObject(Klass* klass) {
        _func_code = nullptr;
        _func_name = nullptr;
        _flags = 0;
        _defaults = nullptr;
        set_klass(klass);
    }

    HiString* func_name() {return _func_name;}
    int flags() {return _flags;}

    Map<HiObject*, HiObject*>* globals(){return _globals;}
    void set_globals(Map<HiObject*, HiObject*>* x) {_globals = x;}
    void set_default(ObjList defaults);
    ObjList defaults(){return _defaults;}
};


#endif //TINYPY_FUNTIONOBJECT_H
