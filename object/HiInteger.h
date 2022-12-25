//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_HIINTEGER_H
#define TINYPY_HIINTEGER_H

#include "HiObject.h"

class HiInteger : public HiObject{
private:
    int _value;
public:
    HiInteger(int x);
    int value(){return _value;}
};

class IntegerKlass : public Klass {
private:
    IntegerKlass(); // 私有构造方法, 单例模式
    static IntegerKlass* instance;

public:
    static IntegerKlass* get_instance();

    virtual void print(HiObject* obj);

    virtual HiObject* add(HiObject *x, HiObject *y);
    virtual HiObject* sub(HiObject *x, HiObject *y);
    virtual HiObject* mul(HiObject *x, HiObject *y);
    virtual HiObject* div(HiObject *x, HiObject *y);
    virtual HiObject* mod(HiObject *x, HiObject *y);

    virtual HiObject* greater(HiObject* x, HiObject *y);
    virtual HiObject* less(HiObject* x, HiObject *y);
    virtual HiObject* equal(HiObject* x, HiObject *y);
    virtual HiObject* not_equal(HiObject* x, HiObject *y);
    virtual HiObject* ge(HiObject* x, HiObject *y);
    virtual HiObject* le(HiObject* x, HiObject *y);
};

#endif //TINYPY_HIINTEGER_H
