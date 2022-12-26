//
// Created by Bochao An on 2022/12/24.
//

#ifndef TINYPY_ARRAYLIST_H
#define TINYPY_ARRAYLIST_H

template<typename T>
class ArrayList {
private:
    int _length;
    T* _array;
    int _size;

    void expand();

public:
    ArrayList(int n = 8);

    void add(T t);
    T pop();

    void insert(int index, T t);

    T get(int index);
    void set(int index, T t);

    int size();
    int length();
};

class HiObject;
typedef ArrayList<HiObject*>* ObjList;
#endif //TINYPY_ARRAYLIST_H
