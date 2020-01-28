#include <iostream>
#include <list>

using namespace std;

int compare(const int& a, const int& b) {
    //自定义降序排列
    return a>b;
}

int main() {

    // 创建链表
    list<int> l1;           // 创建一个空链表
    list<int> l2(10);       // 创建一个链表其有10个空元素
    list<int> l3(5, 20);    // 创建一个链表其有5个元素内容为20
    list<int> l4(l3.begin(), l3.end());     // 创建一个链表其内容为l3的元素
    list<int> l5(l4);       // 创建一个链表其内容为l4的内容

    // 迭代器
    list<int> li;
    for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++) {
        cout << *iter << endl;
    }

    // 判断是否为空
    if (li.empty()) {
        cout << "is empty" << endl;
    } else {
        cout << " is not empty" << endl;
    }

    // 插入，删除
    // 链表前插入
    li.push_front(10);
    li.pop_front();
    // 链表后插入
    li.push_back(10);
    li.pop_back();

    // insert 插入
    li.insert(li.begin(), 10);      // 在链表最前端插入10
    li.insert(li.begin(), 5, 20);   // 在链表最前端插入5个数据内容为20
    list<int> temp(2, 50);
    li.insert(li.begin(), li.begin(), li.end());  // 在链表最前端插入链表temp的全部内容

    // erase 删除
    li.erase(li.begin());       // 删除第一个元素

    // 排序
    // sort() 默认排序，从小到大
    li.sort();
    li.sort(compare);       // 使用自定义的函数进行排序

    // 逆序
    li.reverse();

    return 0;
}