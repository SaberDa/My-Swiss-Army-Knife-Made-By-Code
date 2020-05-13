#include <iostream>
#include <deque>

using namespace std;

// deque, 双端队列
// 时间复杂度：
//      任意元素的读取、修改 常数时间
//      尾部进行插入、删除   常数时间
//      头部进行插入、删除   O(n)

// 构造函数
// deque() 
// deque(int nSize)
// deque(int nSize, const T& t) 值均为t
// deque(const deque&) 复制

// 增加函数
// void push_front(const T& t) : 头部增加一个元素t
// void push_back(const T& t) : 尾部增加一个元素t
// iterator insert(iterator it, const T& t) : 在某一元素前增加一个元素t
// void insert(iterator it, int n, const T& t) : 某一元素前增加n个相同的元素t
// void insert(iterator it, const_iterator first, const_iterator last) : 在某一元素前插入另一个相同类型向量的[first, last)间的数据

// 删除函数
// iterator erase(iterator it) : 删除双端队列中某一个元素
// iterator erase(iterator first, iterator last) : 删除双端队列中[first, last)中的元素
// void pop_front() : 删除队首元素
// void pop_back() : 删除队尾元素
// void clear()

// 遍历函数
// reference at(int pos) : 返回pos位置元素的引用
// reference front() : 返回队首元素的引用
// reference back() : 返回队尾元素的引用
// iterator begin() : 返回向量头指针，指向第一个元素
// iterator end() : 返回向量最后一个元素的下一个元素的指针（不包含在向量中）
// reverse_iterator rbegin() : 反向迭代器，指向最后一个元素
// reverse_iterator rend() : 反向迭代器，指向第一个元素的前一个元素

// 判断函数
// bool empty() const;

// 大小函数
// int size()
// int max_size() : 返回最大可允许的双端队列元素的数量

// 其他函数
// void swap(deque&) : 交换两个同类型的元素
// void assign(int n, const T& t) : 向量中第n个元素的值设置为t

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

    cout << "原始队列 " << endl;
    // for (auto i : d) {
    //     cout << i << endl;
    // } 
    for (int i(0); i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    d.push_front(1);
    d.push_front(3);
    d.push_front(5);

    cout << "在头部插入元素" << endl;
    for (auto i : d) {
        cout << i << " ";
    }
    cout << endl;

    cout << "删除头部元素" << endl;
    d.pop_front();
    for (auto i : d) {
        cout << i << " ";
    }
    cout << endl;

    cout << "删除尾部元素" << endl;
    d.pop_back();
    for (auto i : d) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}