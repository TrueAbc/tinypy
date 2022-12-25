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
    HiInteger(int x){
        _value = x;
    };
    int value(){return _value;}

    virtual void print() override;
    virtual HiObject * add(HiObject *x) override;
    virtual HiObject* greater(HiObject* x) override;
    virtual HiObject* less(HiObject* x) override;
    virtual HiObject* equal(HiObject* x) override;
    virtual HiObject* not_equal(HiObject* x) override;
    virtual HiObject* ge(HiObject* x) override;
    virtual HiObject* le(HiObject* x) override;
};


#endif //TINYPY_HIINTEGER_H
