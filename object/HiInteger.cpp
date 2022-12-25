//
// Created by Bochao An on 2022/12/24.
//

#include "HiInteger.h"
#include "runtime/universe.h"

IntegerKlass* IntegerKlass::instance = nullptr;

IntegerKlass::IntegerKlass() {
}

IntegerKlass *IntegerKlass::get_instance() {
    if (instance == nullptr) {
        instance = new IntegerKlass();
    }
    return instance;
}

HiInteger::HiInteger(int x) {
    _value = x;
    set_klass(IntegerKlass::get_instance());
}


void IntegerKlass::print(HiObject *obj) {
    HiInteger* int_obj = (HiInteger*) obj;
    assert(int_obj && int_obj->klass() == this);
    printf("%d", int_obj->value());
}

HiObject* IntegerKlass::add(HiObject* x, HiObject* y) {
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new HiInteger(ix->value() + iy->value());
}

HiObject* IntegerKlass::sub(HiObject* x, HiObject* y) {
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new HiInteger(ix->value() - iy->value());
}

HiObject* IntegerKlass::mul(HiObject* x, HiObject* y) {
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new HiInteger(ix->value() * iy->value());
}

HiObject* IntegerKlass::div(HiObject* x, HiObject* y) {
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));
    assert(iy->value() != 0);

    return new HiInteger(ix->value() / iy->value());
}

HiObject* IntegerKlass::mod(HiObject* x, HiObject* y) {
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));
    assert(iy->value() != 0);

    return new HiInteger(ix->value() % iy->value());
}

HiObject *IntegerKlass::greater(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() > iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *IntegerKlass::less(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() < iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *IntegerKlass::equal(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() == iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *IntegerKlass::not_equal(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() != iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *IntegerKlass::ge(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() >= iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}

HiObject *IntegerKlass::le(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;
    HiInteger* ix = (HiInteger*) x;
    HiInteger* iy = (HiInteger*) y;

    assert(ix && (ix->klass() == this));
    assert(iy && (iy->klass() == this));

    if (ix->value() <= iy->value()) {
        return Universe::HiTrue;
    } else {
        return Universe::HiFalse;
    }
}