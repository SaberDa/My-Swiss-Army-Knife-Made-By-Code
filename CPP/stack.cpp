#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    // 栈，先进后出

    // stack<int> s;
    // stack<int> v(s);
    // 标准的栈的初始化是直接创建空栈
    // 通过用标准的方式创建向量数组，然后通过复制结构函数的方式进行创建栈，内容就是该vector的内容
    vector<int> v(3, 100);
    stack<int, vector<int> > s(v);

    // 栈和队列只能访问顶层数据
    // 并不断删除数据来进行全部访问

    // top() 返回栈顶元素
    cout << s.top() << endl;
    // 也可以直接对栈顶元素进行修改
    s.top() += 100;

    // push() 入栈
    // 向栈顶插入元素
    // pop() 出栈
    // 弹出栈顶元素
    // 注意，pop() 函数是没有返回值的，如果想要访问后删除需要先 top 然后 pop

    // 利用 empty() 函数进行遍历
    // 使用前先将栈进行复制
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}