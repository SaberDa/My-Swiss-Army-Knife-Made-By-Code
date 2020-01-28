#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    // 初始化
    queue<int> q;
    queue<int> qoo(q);
    vector<int> v(3, 100);
    queue<int, vector<int> > s(v);

    // 栈和队列只能访问顶层数据
    // 并不断删除数据来进行全部访问

    // push() 在队尾插入
    // pop() 弹出队首

    // front() 访问队首元素，并返回
    // back() 访问队尾元素，并返回

    

    return 0;
}