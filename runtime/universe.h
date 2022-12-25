//
// Created by Bochao An on 2022/12/25.
//

#ifndef TINYPY_UNIVERSE_H
#define TINYPY_UNIVERSE_H

#include "object/HiInteger.h"

// 当前用于存放全局唯一的一些变量
class Universe {
public:
    static HiInteger* HiTrue;
    static HiInteger* HiFalse;

    static HiObject* HiNone;

public:
    static void genesis(); // 创建虚拟机中原始的对象结构
    static void destroy(); // 虚拟机退出释放资源, 销毁对象
};


#endif //TINYPY_UNIVERSE_H
