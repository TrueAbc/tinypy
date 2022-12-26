//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_HIOBJECT_H
#define TINYPY_HIOBJECT_H

#include <cassert>
#include <cstdio>
#include "Klass.h"

class Klass;

// 对象系统的基类
class HiObject {
private:
    Klass* _klass;

public:
    Klass* klass(){
        assert(_klass != nullptr);
        return _klass;
    }
    void set_klass(Klass* x){_klass = x;}

    void print();

    HiObject* add(HiObject *x);
    HiObject* sub(HiObject* x);
    HiObject* mul(HiObject *x);
    HiObject* div(HiObject* x);
    HiObject* mod(HiObject* x);

    HiObject* greater(HiObject* x);
    HiObject* less(HiObject* x);
    HiObject* equal(HiObject* x);
    HiObject* not_equal(HiObject* x);
    HiObject* ge(HiObject* x);
    HiObject* le(HiObject* x);
};


#endif //TINYPY_HIOBJECT_H
