//
// Created by Bochao An on 2022/12/26.
//

#include "funtionobject.h"

FunctionKlass* FunctionKlass::instance = nullptr;

FunctionKlass *FunctionKlass::get_instance() {
    if (instance == nullptr) {
        instance = new FunctionKlass();
    }
    return instance;
}
FunctionKlass::FunctionKlass() {
}
void FunctionKlass::print(HiObject *obj) {
    printf("<function :");
    FunctionObject* fo = static_cast<FunctionObject*>(obj);

    assert(fo && fo->klass() == (Klass*) this);
    fo->func_name()->print();
    printf(">");
}

FunctionObject::FunctionObject(HiObject *code_object) {
    CodeObject* co = (CodeObject*) code_object;
    _func_code = co;
    _func_name = co->_co_name;
    _flags = co->_flag;
    set_klass(FunctionKlass::get_instance());
}