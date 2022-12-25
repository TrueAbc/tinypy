//
// Created by Bochao An on 2022/12/25.
//

#ifndef TINYPY_LOOPBLOCK_H
#define TINYPY_LOOPBLOCK_H


class Block {
public:
    unsigned char _type; // 还有其他类型Block
    unsigned int _target; // 跳转地址
    int _level; // 操作数栈深度,

    Block(unsigned char b_type,
          unsigned int b_target,
          int b_level):
          _type(b_type),
          _target(b_target),
          _level(b_level){};
    Block() {
        _type = 0;
        _target = 0;
        _level = 0;
    };
    // 拷贝构造函数
    Block(const Block& b) {
        _type = b._type;
        _target = b._target;
        _level  = b._level;
    }
};


#endif //TINYPY_LOOPBLOCK_H
