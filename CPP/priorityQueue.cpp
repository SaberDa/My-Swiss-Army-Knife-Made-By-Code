#include <queue>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// 初始化
// priority_queue<T, Container, Compare>
// priority_queue<T>    
// 直接输入元素，则使用默认容器和比较函数
// T: 数据类型
// Container: 容器类型，必须是数组实现的容器，比如vector, deque。不能使用list
//            STL 中默认使用 vector
// Compare: 比较方法。如果自定义类型，compare 需要使用结构体的运算符重载完成
struct cmp {
    bool operator() (int &a, int &b) const {
        return a > b;
    }
};
priority_queue<int, vector<int>, cmp> q;

// 常用接口
// size() 
// push() 在队尾进行插入
// pop() 弹出队首元素
// top() 优先队列只允许访问队首元素
// empty()


void visit();
void reVisit1();
void reVisit2();

int main() {

    // reVisit1();
    reVisit2();
    return 0;
}

void visit() {
    // 输出，默认为大顶堆顺序

    priority_queue<int> pq;

    for (int i = 1; i <= 5; i++) {
        pq.push(i*10);
    }
    pq.push(15);
    pq.push(4);
    
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        cout << temp << endl;
    }

}

struct compare {
    bool operator() (int &a, int &b) const {
        return a > b;
    }
};

void reVisit1() {
    // 输出，按小顶堆顺序
    // 方法1：自定义结构体为比较函数

    priority_queue<int, vector<int>, compare> pq;

    for (int i = 1; i <= 5; i++) {
        pq.push(i*10);
    }
    pq.push(5);
    pq.push(15);

    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        cout << temp << endl;
    }

}

void reVisit2() {
    // 使用 greater<int> 须导入头文件 <functional>
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i<= 5; i++) {
        pq.push(i*10);
    }
    pq.push(5);
    pq.push(15);

    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        cout << temp << endl;
    }

}



