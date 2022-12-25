//
// Created by Bochao An on 2022/12/24.
//

#include "HiInteger.h"
#include "runtime/universe.h"

void HiInteger::print() {
    printf("%d", _value);
}

HiObject *HiInteger::add(HiObject *x) {
    return new HiInteger(_value + ((HiInteger*)x)->_value);
}

// todo 当前返回的是1和0, 后面要改为True和False对象
HiObject *HiInteger::greater(HiObject *x) {
    if (_value > ((HiInteger*)x)->_value){
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *HiInteger::less(HiObject *x) {
    if(_value < ((HiInteger* )x)->_value) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *HiInteger::equal(HiObject *x) {
    if(_value == ((HiInteger* )x)->_value) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *HiInteger::not_equal(HiObject *x) {
    if(_value != ((HiInteger* )x)->_value) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *HiInteger::ge(HiObject *x) {
    if(_value >= ((HiInteger* )x)->_value) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *HiInteger::le(HiObject *x) {
    if(_value <= ((HiInteger* )x)->_value) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}