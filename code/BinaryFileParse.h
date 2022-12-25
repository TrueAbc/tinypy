//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_BINARYFILEPARSE_H
#define TINYPY_BINARYFILEPARSE_H

#include "util/BufferedInputStream.h"
#include "object/HiInteger.h"
#include "CodeObject.h"

class BinaryFileParse {
private:
    BufferedInputStream* file_stream;
    int cur;
    ArrayList<HiString*> _string_table;

public:
    BinaryFileParse(BufferedInputStream* stream);

    CodeObject* parse();

    CodeObject* get_code_object();
    HiString* get_byte_codes();
    HiString* get_no_table();
    HiString* get_name();

    HiString* get_file_name();

    ArrayList<HiObject*>* get_consts();
    ArrayList<HiObject*>* get_names();
    ArrayList<HiObject*>* get_var_names();
    ArrayList<HiObject*>* get_free_vars();
    ArrayList<HiObject*>* get_cell_vars();

    HiString* get_string();
    ArrayList<HiObject*>* get_tuple();
};


#endif //TINYPY_BINARYFILEPARSE_H
