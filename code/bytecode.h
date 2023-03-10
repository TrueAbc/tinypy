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
        GREATER_EQUAL, // >=

        IN,
        NOT_IN,
        IS, // is
        IS_NOT, // is not
        EXC_MATCH
    };

    static const unsigned char POP_TOP = 1;

    static const unsigned char BINARY_ADD = 23;
    static const unsigned char PRINT_ITEM = 71;
    static const unsigned char PRINT_NEWLINE = 72;

    static const unsigned char BREAK_LOOP = 80;

    static const unsigned char RETURN_VALUE = 83;

    static const unsigned char POP_BLOCK = 87;

    // TODO: This is a separator
    static const unsigned char HAVE_ARGUMENT = 90; /* Opcodes from here have an argument: */

    static const unsigned char STORE_NAME = 90; /* Index in name list */

    static const unsigned char STORE_GLOBAL = 97;
    static const unsigned char LOAD_CONST = 100;
    static const unsigned char LOAD_NAME = 101; /* Index in name list */

    static const unsigned char COMPARE_OP = 107;

    /* number of bytes to skip*/
    static const unsigned char JUMP_FORWARD = 110;
    static const unsigned char JUMP_ABSOLUTE = 113;
    static const unsigned char POP_JUMP_IF_FALSE = 114;
    static const unsigned char LOAD_GLOBAL = 116; /* Index in name list */

    static const unsigned char SETUP_LOOP = 120; /* Target address (relative) */
    static const unsigned char LOAD_FAST  = 124; /* Local variable number */
    static const unsigned char STORE_FAST = 125; /* Local variable number */

    static const unsigned char CALL_FUNCTION = 131;
    static const unsigned char MAKE_FUNCTION = 132;
};
#endif //TINYPY_BYTECODE_H
