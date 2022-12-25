//
// Created by Bochao An on 2022/12/24.
//

#include "HiString.h"
#include "runtime/universe.h"
#include "string.h"


HiString::HiString(const char *x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
}

HiString::HiString(const char *x, const int length) {
    _length = length;
    _value = new char[_length];

    for (int i = 0; i < length; ++i) {
        _value[i] = x[i];
    }
}

HiObject *HiString::equal(HiObject *x) {
    HiString* sx = (HiString *) x;
    if(_length != sx->_length) {
        return Universe::HiFalse;
    }
    for (int i = 0; i < _length; ++i) {
        if(_value[i] != sx->_value[i]) {
            return Universe::HiFalse;
        }
    }
    return Universe::HiTrue;
}