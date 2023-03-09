
#pragma once
#include <assert.h>
#include <stdlib.h>
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
private:
    T *holder;

    
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
    }

}

template<class T>
stack<T>::stack(const stack& other) 
{   
    currentSizeLimit = other.currentSizeLimit;
    holder = new T[currentSizeLimit];
    pointerPosition = other.pointerPosition;
    memcpy(holder, other.holder, pointerPosition * sizeof(T));
}

template<class T>
stack<T>& stack<T>::operator=(const stack& other) 
{   
    if (holder) delete[] holder;
    currentSizeLimit = other.currentSizeLimit;
    holder = new T[currentSizeLimit];
    pointerPosition = other.pointerPosition;
    memcpy(holder, other.holder, pointerPosition * sizeof(T));
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
        T* temp = reinterpret_cast<T*>(realloc(holder, currentSizeLimit));
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