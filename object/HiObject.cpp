//
// Created by Bochao An on 2022/12/24.
//

#include "HiObject.h"

void HiObject::print() {
    return _klass->print(this);
}

HiObject *HiObject::add(HiObject *x) {
    return _klass->add(this, x);
}

HiObject *HiObject::sub(HiObject *x) {
    return _klass->sub(this, x);
}

HiObject *HiObject::mul(HiObject *x) {
    return _klass->mul(this, x);
}

HiObject *HiObject::div(HiObject *x) {
    return _klass->div(this, x);
}

HiObject *HiObject::mod(HiObject *x) {
    return _klass->mod(this, x);
}

HiObject *HiObject::greater(HiObject *x) {
   return _klass->greater(this, x);
}

HiObject *HiObject::less(HiObject *x) {
   return _klass->less(this, x);
}

HiObject *HiObject::equal(HiObject *x) {
    return _klass->equal(this, x);
}

HiObject *HiObject::not_equal(HiObject *x) {
    return _klass->not_equal(this, x);
}

HiObject *HiObject::ge(HiObject *x) {
    return _klass->ge(this, x);
}

HiObject *HiObject::le(HiObject *x) {
    return _klass->le(this, x);
}