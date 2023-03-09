#ifdef MYSTACK
#include "stack/stack.hpp"
#endif
#include <iostream>
int main () {
#ifdef MYSTACK
    stack<int> a;
    for (int i = 0; i < 40; i ++) {
        a.push(i);
    }
    std::cout << a.pop() << std:: endl;
#endif
    return 0;
}