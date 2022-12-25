//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_HIOBJECT_H
#define TINYPY_HIOBJECT_H

#include "stdio.h"

// 对象系统的基类
class HiObject {
public:
    virtual void print(){};

    virtual HiObject* add(HiObject *x){};
    virtual HiObject* greater(HiObject* x){};
    virtual HiObject* less(HiObject* x){};
    virtual HiObject* equal(HiObject* x){};
    virtual HiObject* not_equal(HiObject* x){};
    virtual HiObject* ge(HiObject* x){};
    virtual HiObject* le(HiObject* x){};
};


#endif //TINYPY_HIOBJECT_H
