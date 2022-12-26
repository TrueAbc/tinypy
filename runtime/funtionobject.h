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

    unsigned int _flags;

public:
    FunctionObject(HiObject* code_object);
    FunctionObject(Klass* klass) {
        _func_code = nullptr;
        _func_name = nullptr;
        _flags = 0;
        set_klass(klass);
    }

    HiString* func_name() {return _func_name;}
    int flags() {return _flags;}
};


#endif //TINYPY_FUNTIONOBJECT_H
