#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

// Vector: 是一个封装了动态大小数组的顺序容器
// 顺序序列：按照严格的线性顺序排列
// 动态数组：支持对序列中的任意元素进行快速直接访问，甚至可以通过指针算术进行该操作。
// Allocator-aware: 容器使用一个内存分配器对象来动态的处理它的存储需求

// 构造函数
// vector()  创建一个空vector
// vector(int x) 创建一个元素个数为x的vector
// vector(int x, const t& t) 创建一个元素个数为x且值均为t的vector
// vector(const vector&) 复制构造函数
// vector(begin, end) 复制 [begin, end) 区间内另一个数组的元素到该vector中

// 增加函数
// void push_back(const T& x)  向量尾部增加一个元素x
// iterator insert(iterator it, const T& x) 向量中迭代器指向元素前增加一个元素x
// iterator insert(iteratir it, int n, const T& x) 向量中迭代器指向元素前增加n个相同的元素x
// iterator insert(iterator it, const_iterator first, const_iterator last) 向量中迭代器指向元素前插入另一个相同类型向量的 [begin, last) 间的数据

// 删除函数
// void pop_back() 删除向量中最后一个元素
// void clear() 清空向量中所有元素
// iterator erase(iterator it) 删除向量中迭代器指向元素
// iterator erase(iterator first, iterator last) 删除向量中 [first, last) 中的元素

// 遍历函数
// reference at(int pos) 返回pos位置元素的引用
// reference front() 返回首元素的引用
// reference back() 返回尾元素的引用
// iterator begin() 返回向量头指针，指向第一个元素
// iterator end() 返回向量尾指针，指向最后一个元素的下一个位置
// reverse_iterator rbegin() 反向迭代器，指向最后一个元素
// reverse_iterator rend() 反向迭代器，指向第一个元素之前的位置

// 判断函数
// bool empty() const 判断向量是否为空，若为空，则向量中无元素

// 大小函数
// int size() const 返回向量中元素的个数
// int capacity() const 返回当前向量中所能容纳的最大元素值
// int max_size() const 返回最大允许的vector元素数量值

// 其他函数
// void swap(vector&) 交换两个同类型向量的数据
// void assign(int n, const T& x) 设置向量中第n个元素的值为x
// void assign(const_iterator first, const_iterator last) 向量中 [first, last) 中元素设置为当前元素

// 便捷记忆
// vector<类型>标识符
// vector<类型>标识符(最大容量)
// vector<类型>标识符(最大容量，初始所有值)

int popAndPush();
int isEmpty();
void selfSort();
void visit();
void twoDimensionalMatrix1();
void twoDimensionalMatrix2();

int main() {

    // popAndPush();
    isEmpty();
    // selfSort();
    // visit();
    // twoDimensionalMatrix1();
    // twoDimensionalMatrix2();
    return 0;
}

int popAndPush() {
    vector<int> obj;
    for (int i = 0; i < 10; i++) {
        obj.push_back(i);
        cout << obj[i] << " " << endl;
    }
    for (int i = 0; i < 5; i++) {
        obj.pop_back();
    }
    cout << "\n" << endl;
    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << endl;
    }
    return 0;
}

int isEmpty() {
    vector<int> obj;
    for (int i = 0; i < 10; i++) {
        obj.push_back(i);
        cout << obj[i] << endl;
    }
    obj.clear();
    if (obj.empty()) {
        cout << "it is clear" << endl;
    } else {
        cout << "there is left" << endl;
    }
    return 0;
}

void selfSort() {
    vector<int> obj;

    obj.push_back(11);
    obj.push_back(3);
    obj.push_back(44);

    sort(obj.begin(), obj.end());

    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << endl;
    }

    reverse(obj.begin(), obj.end());
    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << endl;
    }

}

void visit() {
    vector<int> obj;

    for (int i = 0; i < 10; i++) {
        obj.push_back(i);
    }

    // 利用数组进行访问
    for (int i = 0; i < obj.size(); i++) {
        cout << obj[i] << " ";
    }
    cout << " " << endl;

    // 利用迭代器访问
    // 声明一个迭代器，来访问 vector 容器
    // 作用：遍历或者指向 vector 容器的元素
    // vector<int>::iterator it;
    // 利用 auto 声明迭代器
    auto it = obj.begin();
    for (it = obj.begin(); it != obj.end(); it++) {
        cout << *it << " ";
    }
    cout << " " << endl;
}

void twoDimensionalMatrix1() {
    int N = 5, M = 6;

    // 定义行数
    vector<vector<int> > obj(N);
    // 定义列数
    for (int i = 0; i < obj.size(); i++) {
        obj[i].resize(M);
    }
    
    for (int i = 0; i < obj.size(); i++) {
        for (int j = 0; j < obj[i].size(); j++) {
            cout << obj[i][j] << " ";
        }
        cout << " " << endl;
    }
}

void twoDimensionalMatrix2() {
    int N = 5, M = 6;

    vector<vector<int> > obj(N, vector<int>(M));

    for (int i = 0; i < obj.size(); i++) {
        for (int j = 0; j < obj[i].size(); j++) {
            cout << obj[i][j] << " ";
        }
        cout << " " << endl;
    }
}