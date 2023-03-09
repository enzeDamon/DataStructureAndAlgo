#ifdef MYSTACK
#include "stack/stack.hpp"
#include <stack>
#endif
#include <iostream>
int main () {
#ifdef MYSTACK
    stack<int> a;
    std::stack<int> std_a;
    for (int i = 0; i < 40; i ++) {
        a.push(i);
        std_a.push(i);
    }
    stack<int> b(a);
    stack<int> c = a;
    std::cout << b.pop() << std:: endl;
    // stl 中 stack top 拿值，push是推值进去，
    // pop是拿值，拿值之前应该要用empty来进行验证
    // stl 中的stack都是用链表来实现的
    std::cout << std_a.empty() << std:: endl;
#endif
    return 0;
}