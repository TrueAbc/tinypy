//
// Created by Bochao An on 2022/12/24.
//

#include "interpreter.h"
#include "universe.h"


void Interpreter::run(CodeObject* code){
#define PUSH(x) _stack->add((x))
#define POP() _stack->pop()
#define STACK_LEVEL() _stack->size()

    int pc = 0;
    int code_length = code->_bytecodes->length();

    _stack = new ArrayList<HiObject*>(code->_stack_size);
    _consts = code->_consts;
    _loop_stack = new ArrayList<Block*>();

    while (pc < code_length) {

        unsigned char op_code = code->_bytecodes->value()[pc++];
        bool has_argument = (op_code & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;

        // 带参数的字节码参数有两个字节
        if(has_argument) {
            int byte1 = (code->_bytecodes->value()[pc++] & 0xff);
            op_arg = ((code->_bytecodes->value()[pc++] & 0xff) << 8) | byte1;
        }
        HiInteger* lhs, *rhs;
        HiObject* v, *w, *u, *attr;
        Block* b;

        switch (op_code) {
            case ByteCode::LOAD_CONST:
                PUSH(_consts->get(op_arg));
                break;
            case ByteCode::PRINT_ITEM:
                v = POP();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;
            case ByteCode::BINARY_ADD:
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;
            case ByteCode::RETURN_VALUE:
                POP();
                break;
            case ByteCode::COMPARE_OP:
                w = POP();
                v = POP();
                switch (op_arg) {
                    case ByteCode::GREATER:
                        PUSH(v->greater(w));
                        break;

                    case ByteCode::LESS:
                        PUSH(v->less(w));
                        break;

                    case ByteCode::EQUAL:
                        PUSH(v->equal(w));
                        break;

                    case ByteCode::NOT_EQUAL:
                        PUSH(v->not_equal(w));
                        break;

                    case ByteCode::GREATER_EQUAL:
                        PUSH(v->ge(w));
                        break;

                    case ByteCode::LESS_EQUAL:
                        PUSH(v->le(w));
                        break;

                    default:
                        printf("Error: Unrecognized compare op: %d\n", op_arg);
                }
                break;
            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if (v == Universe::HiFalse)
                    pc = op_arg;
                break;
            case ByteCode::JUMP_FORWARD:
                pc += op_arg;
                break;
            case ByteCode::JUMP_ABSOLUTE:
                pc = op_arg;
                break;
            case ByteCode::SETUP_LOOP:
                _loop_stack->add(new Block(
                        op_code, pc + op_arg,
                        STACK_LEVEL()
                        ));
                break;
            case ByteCode::POP_BLOCK:
                // 正常退出
                b = _loop_stack->pop();
                while(STACK_LEVEL() > b->_level) {
                    POP();
                }
                break;
            case ByteCode::BREAK_LOOP:
                b = _loop_stack->pop();
                while (STACK_LEVEL() > b->_level) {
                    POP();
                }
                pc = b->_target;
                break;
            case ByteCode::STORE_NAME:
                v = POP();
                _names.put(code->_names->get(op_arg), new HiInteger(((HiInteger*)v)->value()));
                break;
            case ByteCode::LOAD_NAME:
                w = code->_names->get(op_arg);
                v = _names.get(w);
                PUSH(v);
                break;
            default:
                printf("Error: Unrecognized byte code %d\n", op_code);
        }
    }
}