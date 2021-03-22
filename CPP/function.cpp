#include <iostream>
#include <functional>

using namespace std;

/*
 * function 是一种通用、多态的函数封装
 * 它的实例可以对任何可以调用的目标实体进行存储、复制和调用操作
 * 它也是对 C++ 中现有的可调用实体的一张类型安全的包裹 （通常，函数指针的调用不是安全类型）
 * 简而言之，function 就是函数的容器
*/

int foo(int para) {
    return para;
}

int main() {

    // function 包装了一个返回值为 int, 参数为 int 的函数
    function<int(int)> func = foo;
    cout << func(10) << endl;

    return 0;
}