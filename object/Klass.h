//
// Created by Bochao An on 2022/12/25.
//

#ifndef TINYPY_KLASS_H
#define TINYPY_KLASS_H

#include "HiObject.h"

class HiObject;
class HiString;

class Klass {
private:
    HiString* _name;

public:
    Klass() {};

    void set_name(HiString* x) {_name = x;}
    HiString* name() {return _name;}

    // todo 对于Builtin变量, 可以修改一下打印函数
    virtual void print(HiObject* obj){};

    virtual HiObject* add(HiObject *x, HiObject *y){return 0;};
    virtual HiObject* sub(HiObject *x, HiObject *y){return 0;};
    virtual HiObject* mul(HiObject *x, HiObject *y){return 0;};
    virtual HiObject* div(HiObject *x, HiObject *y){return 0;};
    virtual HiObject* mod(HiObject *x, HiObject *y){return 0;};

    virtual HiObject* greater(HiObject* x, HiObject *y){return 0;};
    virtual HiObject* less(HiObject* x, HiObject *y){return 0;};
    virtual HiObject* equal(HiObject* x, HiObject *y){return 0;};
    virtual HiObject* not_equal(HiObject* x, HiObject *y){return 0;};
    virtual HiObject* ge(HiObject* x, HiObject *y){return 0;};
    virtual HiObject* le(HiObject* x, HiObject *y){return 0;};
};


#endif //TINYPY_KLASS_H
