#include <iostream>

using namespace std;

class A {
    public:
    A() {
        cout << "A()" << endl;
    }
    A(int a) {
        cout << "A(int a)" << endl;
    }
};

int main() {

    // 栈上
    cout << "a~~~~~~" << endl;
    // 这里声明了一个函数，但是没有传入的参数，返回值为类类型
    A a();
    cout << "b~~~~~~" << endl;
    // 默认调用 "对象名()" 这个构造函数构造对象
    A b;
    cout << "c~~~~~~" << endl;
    // 调用默认响应的构造函数构造对象
    A c(1);

    // 堆上
    // 加括号与不加括号没有区别，都调用默认的构造函数
    cout << "d~~~~~~" << endl;
    A *d = new A();
    cout << "e~~~~~~" << endl;
    A *e = new A;

    // 对于内置类型而言，加括号是进行了初始化，不加是未进行初始化
    int *f = new int();
    int *g = new int;
    cout << "f~~~~~~" << *f << endl;
    cout << "g~~~~~~" <<*g << endl;

    // 输出
    // a~~~~~~
    // b~~~~~~
    // A()
    // c~~~~~~
    // A(int a)
    // d~~~~~~
    // A()
    // e~~~~~~
    // A()
    // f~~~~~~0
    // g~~~~~~16195360

    return 0;
}