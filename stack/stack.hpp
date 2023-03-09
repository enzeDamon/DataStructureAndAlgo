
#pragma once
#include <assert.h>
#include <cstdlib>
#include <cstring>
template<class T>
#define INITSIZE (20) 
class stack
{
public:
    stack();
    ~stack();
    stack(const stack &);
    stack& operator= (const stack&);
    void push(const T &ele);
    T& pop();
    int currentSizeLimit;
    int pointerPosition;
    T *holder;
private:


    
};
template<class T>
stack<T>::stack() 
{
    holder = new T[INITSIZE];
    currentSizeLimit = INITSIZE;
    pointerPosition = 0;
}
template<class T>
stack<T>::~stack()
{
    if (holder != nullptr) {
        delete[] holder;
        holder = nullptr;
    }

}
#include <iostream>
template<class T>
stack<T>::stack(const stack<T>& other) 
{   
    currentSizeLimit = other.currentSizeLimit;
    pointerPosition = other.pointerPosition;
    holder = new T[currentSizeLimit];
    std::memcpy(holder, other.holder, pointerPosition * sizeof(T));
}

template<class T>
stack<T>& stack<T>::operator=(const stack<T>& other) 
{   
    if (holder) delete[] holder;
    currentSizeLimit = other.currentSizeLimit;
    holder = new T[currentSizeLimit];
    pointerPosition = other.pointerPosition;
    std::memcpy(holder, other.holder, pointerPosition * sizeof(T));
    return *this;
}

template<class T>
void stack<T>::push(const T &ele) 
{   
    // 就这个标记的是该进去的位置，就是下标，0就是该到第一个，
    // 所以不应该-1，应该直接进去， 这种情况直接倍增内存
    if (pointerPosition == currentSizeLimit)
    {
        currentSizeLimit *= 2;
        T* temp = reinterpret_cast<T*>(std::realloc(holder, sizeof(T)*currentSizeLimit));
        holder = temp;
    }
    holder[pointerPosition++] = ele;
}

template<class T>
T& stack<T>::pop() 
{

    if (pointerPosition) return holder[--pointerPosition];
    else assert("No element in stack");
}