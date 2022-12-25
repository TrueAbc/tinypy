//
// Created by Bochao An on 2022/12/24.
//

#include "BinaryFileParse.h"
#include "runtime/universe.h"
#include <iostream>

CodeObject* BinaryFileParse::parse() {
    int magic_number = file_stream->read_int();
    printf("magic number is 0x%x\n", magic_number);
    int moddate = file_stream->read_int();
    printf("moddate is 0x%x\n", moddate);

    char object_type = file_stream->read();
    if(object_type == 'c'){
        CodeObject* result = get_code_object();
        printf("parse OK!\n");
        return result;
    }

    return nullptr;
}

BinaryFileParse::BinaryFileParse(BufferedInputStream *stream) {
    this->file_stream = stream;
}

CodeObject *BinaryFileParse::get_code_object() {
    int argcount = file_stream->read_int(); // 参数
    std::cout<< argcount << std::endl;
    int nlocals = file_stream->read_int();
    int stacksize = file_stream->read_int();
    int flags = file_stream->read_int();
    std::cout<< flags << std::endl;

    HiString* byte_codes = get_byte_codes();
    ArrayList<HiObject*> * consts = get_consts();
    ArrayList<HiObject*> * names = get_names();
    ArrayList<HiObject*> * var_names = get_var_names();
    ArrayList<HiObject*> * free_vars = get_free_vars();
    ArrayList<HiObject*> * cell_vars = get_cell_vars();
    HiString* file_name = get_file_name();
    HiString* module_name = get_name();
    int begin_line_no = file_stream->read_int();
    HiString* lnotab = get_no_table();

    return new CodeObject(argcount, nlocals, stacksize, flags, byte_codes, consts,
                          names, var_names, free_vars, cell_vars, file_name, module_name,
                          begin_line_no, lnotab);

}

HiString *BinaryFileParse::get_byte_codes() {
    // 字节码以s开始, 跟一个整数表示长度, 最后n个字节
    assert(file_stream->read() == 's');
    return get_string();
}

HiString *BinaryFileParse::get_name() {
    char ch = file_stream->read();
    if (ch == 's') return get_string();
    else if (ch == 't') {
        HiString* str = get_string();
        _string_table.add(str);
        return str;
    } else if (ch == 'R'){
        return _string_table.get(file_stream->read_int());
    }
    return nullptr;
}

HiString *BinaryFileParse::get_file_name() {
    return get_name();
}

HiString *BinaryFileParse::get_no_table() {
    char ch = file_stream->read();
    if (ch != 's' && ch != 't') {
        file_stream->unread();
        return nullptr;
    }

    return get_string();
}

HiString *BinaryFileParse::get_string() {
    int length = file_stream->read_int();
    char* str_value = new char[length];

    for (int i = 0; i < length; ++i) {
        str_value[i] = file_stream->read();
    }
    HiString*s = new HiString(str_value, length);

    delete[] str_value;

    return s;
}

ArrayList<HiObject *> *BinaryFileParse::get_consts() {
    if (file_stream->read() == '(') {
        return get_tuple();
    }
    file_stream->unread();
    return nullptr;
}

ArrayList<HiObject *> *BinaryFileParse::get_names() {
    if (file_stream->read() == '(') {
        return get_tuple();
    }
    file_stream->unread();
    return nullptr;
}

ArrayList<HiObject *> *BinaryFileParse::get_var_names() {
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

ArrayList<HiObject *> *BinaryFileParse::get_free_vars() {
    if (file_stream->read() == '(') {
        return get_tuple();
    }
    file_stream->unread();
    return nullptr;
}


ArrayList<HiObject*>* BinaryFileParse::get_cell_vars() {
    if (file_stream->read() == '(') {
        return get_tuple();
    }

    file_stream->unread();
    return NULL;
}

// tuple类型以'(' 开始, 后面是n个元素
ArrayList<HiObject *> *BinaryFileParse::get_tuple() {
    int length = file_stream->read_int();
    HiString* str;
    ArrayList<HiObject*> * list = new ArrayList<HiObject*>(length);
    for (int i = 0; i < length; ++i) {
        char obj_type = file_stream->read();
        switch (obj_type) {
            case 'c':
                std::cout<<"get a code object." << std::endl;
                list->add(get_code_object());
                break;
            case 'i':
                list->add(new HiInteger(file_stream->read_int()));
                break;
            case 'N':
                list->add(Universe::HiNone);
                break;
            case 't':
                str = get_string();
                list->add(str);
                _string_table.add(str);
                break;
            case 's':
                list->add(get_string());
                break;
            case 'R':
                list->add(_string_table.get(file_stream->read_int()));
                break;
        }
    }
    return list;
}