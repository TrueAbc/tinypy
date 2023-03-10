//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_HISTRING_H
#define TINYPY_HISTRING_H

#include "HiObject.h"

class StringKlass : public Klass {
private:
    StringKlass();
    static StringKlass* instance;

public:
    static StringKlass* get_instance();

    virtual HiObject* equal(HiObject* x, HiObject* y);
    virtual void print(HiObject* obj);
};

class HiString : public HiObject{
private:
    char* _value;
    int _length;

public:
    HiString(const char *x);
    HiString(const char *x, const int length);

    const char* value() {
        return _value;
    }
    int length() {
        return _length;
    }

};


#endif //TINYPY_HISTRING_H
