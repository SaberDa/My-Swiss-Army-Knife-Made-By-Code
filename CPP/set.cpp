#include <iostream>
#include <set>

using namespace std;

int main() {

    set<int> s;

    // insert() 插入
    // 默认升序插入
    s.insert(10);
    s.insert(5);
    s.insert(22);

    // 迭代器
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }

    // find() 查找元素
    // find() 方法返回一个迭代器指针，因此需要 * 的方式来获取值
    cout << *s.find(4) << endl;

    // 删除
    s.erase(s.begin());     // 删除第一个元素
    s.erase(s.begin(), s.end());  // 删除前四个元素

    // 清空
    s.clear();      // 清空元素，内存空间不会释放




    return 0;
}