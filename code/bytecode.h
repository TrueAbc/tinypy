//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_BYTECODE_H
#define TINYPY_BYTECODE_H
class ByteCode {
public:
    enum COMPARE {
        LESS = 0, // <
        LESS_EQUAL, // <=
        EQUAL, // !=
        NOT_EQUAL, // !=
        GREATER, // >
        GREATER_EQUAL // >=
    };

    static const unsigned char BINARY_ADD = 23;
    static const unsigned char PRINT_ITEM = 71;
    static const unsigned char PRINT_NEWLINE = 72;

    static const unsigned char BREAK_LOOP = 80;

    static const unsigned char RETURN_VALUE = 83;

    static const unsigned char POP_BLOCK = 87;

    // TODO: This is a separator
    static const unsigned char HAVE_ARGUMENT = 90; /* Opcodes from here have an argument: */

    static const unsigned char STORE_NAME = 90; /* Index in name list */

    static const unsigned char LOAD_CONST = 100;
    static const unsigned char LOAD_NAME = 101; /* Index in name list */

    static const unsigned char COMPARE_OP = 107;

    /* number of bytes to skip*/
    static const unsigned char JUMP_FORWARD = 110;
    static const unsigned char JUMP_ABSOLUTE = 113;
    static const unsigned char POP_JUMP_IF_FALSE = 114;

    static const unsigned char SETUP_LOOP = 120; /* Target address (relative) */

};
#endif //TINYPY_BYTECODE_H
