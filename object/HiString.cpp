//
// Created by Bochao An on 2022/12/24.
//


#include "runtime/universe.h"
#include "HiString.h"
#include <cstring>


StringKlass* StringKlass::instance = nullptr;
StringKlass::StringKlass() {
}

StringKlass* StringKlass::get_instance() {
    if (instance == nullptr) {
        instance = new StringKlass();
    }
    return instance;
}


HiString::HiString(const char *x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
    set_klass(StringKlass::get_instance());
}

HiString::HiString(const char *x, const int length) {
    _length = length;
    _value = new char[_length];

    for (int i = 0; i < length; ++i) {
        _value[i] = x[i];
    }
    set_klass(StringKlass::get_instance());
}

HiObject *StringKlass::equal(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass()) return Universe::HiFalse;

    HiString* sx = (HiString*) x;
    HiString* sy = (HiString*) y;

    assert(sx && sx->klass() == this);
    assert(sy && sy->klass() == this);

    if (sx->length() != sy->length())
        return Universe::HiFalse;

    for (int i = 0; i < sx->length(); ++i) {
        if (sx->value()[i] != sy->value()[i])
            return Universe::HiFalse;
    }

    return Universe::HiTrue;
}

void StringKlass::print(HiObject *obj) {
    HiString* sobj = (HiString*) obj;
    assert(sobj && sobj->klass() == this);

    for (int i = 0; i < sobj->length(); ++i) {
        printf("%c", sobj->value()[i]);
    }
}