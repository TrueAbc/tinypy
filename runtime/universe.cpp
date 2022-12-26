//
// Created by Bochao An on 2022/12/25.
//

#include "universe.h"

HiInteger* Universe::HiTrue = nullptr;
HiInteger* Universe::HiFalse = nullptr;
HiObject* Universe::HiNone = nullptr;

void Universe::genesis() {
    // 打印出的内容也是 1
    HiTrue = new HiInteger(1);
    HiFalse = new HiInteger(0);

    HiNone = new HiObject();
}

void Universe::destroy() {

}
