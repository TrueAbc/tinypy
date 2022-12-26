//
// Created by Bochao An on 2022/12/24.
//

#include "interpreter.h"
#include "universe.h"
#include "frameobject.h"
#include "funtionobject.h"


void Interpreter::eval_frame(){
#define PUSH(x) _frame->stack()->add((x))
#define POP() _frame->stack()->pop()
#define STACK_LEVEL() _frame->stack()->size()

    while (_frame->has_more_codes()) {

        unsigned char op_code = _frame->get_op_code();
        bool has_argument = (op_code & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int op_arg = -1;

        // 带参数的字节码参数有两个字节
        if(has_argument) {
            op_arg = _frame->get_op_arg();
        }
        HiInteger* lhs, *rhs;
        HiObject* v, *w, *u, *attr;
        Block* b;
        FunctionObject* fo;

        switch (op_code) {
            case ByteCode::LOAD_CONST:
                PUSH(_frame->consts()->get(op_arg));
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
                _ret_value = POP();
                if (_frame->is_first_frame())
                    return;
                leave_frame();
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
                    _frame->set_pc(op_arg);
                break;
            case ByteCode::JUMP_FORWARD:
                _frame->set_pc(op_arg + _frame->get_pc());
                break;
            case ByteCode::JUMP_ABSOLUTE:
                _frame->set_pc(op_arg);
                break;
            case ByteCode::SETUP_LOOP:
                _frame->loop_stack()->add(
                        new Block(
                        op_code, _frame->get_pc() + op_arg,
                        STACK_LEVEL()
                        ));
                break;
            case ByteCode::POP_BLOCK:
                // 正常退出
                b = _frame->loop_stack()->pop();
                while(STACK_LEVEL() > b->_level) {
                    POP();
                }
                break;
            case ByteCode::BREAK_LOOP:
                b = _frame->loop_stack()->pop();
                while (STACK_LEVEL() > b->_level) {
                    POP();
                }
                _frame->set_pc(b->_target);
                break;
            case ByteCode::STORE_NAME:
                v = _frame->names()->get(op_arg);
                w = POP();
                _frame->locals()->put(v, w);
                break;
            case ByteCode::LOAD_NAME:
                w = _frame->names()->get(op_arg);
                v = _frame->locals()->get(w);
                PUSH(v);
                break;
            case ByteCode::MAKE_FUNCTION:
                v = POP();
                fo = new FunctionObject(v);
                PUSH(fo);
                break;
            case ByteCode::CALL_FUNCTION:
                build_frame(POP()); // 弹出的对象已经是一个FunctionObject了
                break;
            default:
                printf("Error: Unrecognized byte code %d\n", op_code);
        }
    }
}

void Interpreter::build_frame(HiObject *callable) {
    FrameObject* frame = new FrameObject((FunctionObject*) callable);
    frame->set_sender(_frame);
    _frame = frame;
}

void Interpreter::run(CodeObject *code) {
    _frame = new FrameObject(code);
    eval_frame();
    destroy_frame();
}

void Interpreter::leave_frame() {
    destroy_frame();
    PUSH(_ret_value);
}

void Interpreter::destroy_frame() {
    FrameObject* temp = _frame;
    _frame = _frame->sender();

    delete temp;
}