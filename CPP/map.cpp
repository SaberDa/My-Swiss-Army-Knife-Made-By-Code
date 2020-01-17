#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

// map 的基本操作函数
// begin()
// end()
// clear()
// count() 返回指定元素出现的次数
// empty()
// equal_range() 返回特殊条目的迭代器
// erase() 删除一个元素
// find() 查找一个元素
// get_allocator() 返回map的配置器
// insert() 
// key_comp() 返回比较元素key的函数
// lower_bound() 返回键值 >= 给定元素的第一个位置
// max_size() 返回可以容纳的最大元素个数
// rbegin() 返回一个指向 map 尾部的逆向迭代器
// rend() 
// size()
// swap() 交换两个 map
// upper_bound() 返回键值 > 给定元素的第一个位置
// value_comp() 返回比较元素 value 的函数

void insert1();
void insert2();
void insert3();
void insertSuccess();
void reVisit();
void arrayVisit();
void find1();
void find2();
void delete1();
void compare1();

int main() {

    // insert1();
    // insert2();
    // insert3();
    // insertSuccess();
    // reVisit();
    // arrayVisit();
    // find1();
    // find2();
    // delete1();
    compare1();
    return 0;
}


// 以下三种插入方式，pair 和 value_type 是完全一样的，在数据的插入上涉及到集合的唯一性这个概念
// 集合的唯一性：即 map 中有这个关键字时，insert 操作是插入不了数据的
// 但是使用数组方式就可以覆盖掉以前该关键字的值
/*
这个操作是非法的
mapStudent.insert(map<int, string>::value_type (1, "one"));
mapStudent.insert(map<int, string>::value_type (1, "two"));

这个操作是合法的
mapStudent[1] = "one";
mapStudent[1] = "two";
*/

void insert1() {
    // 用insert插入 pair 数据
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "one"));
    mapStudent.insert(pair<int, string>(2, "two"));
    mapStudent.insert(pair<int, string>(3, "three"));

    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

void insert2() {
    // 用insert插入 value_type 数据
    map<int, string> mapStudent;
    mapStudent.insert(map<int, string>::value_type (1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent.insert(map<int, string>::value_type (3, "three"));

    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter-> first << " " << iter->second << endl;
    }
}

void insert3() {
    // 用数组方式插入数据
    map<int, string> mapStudent;
    mapStudent[1] = "one";
    mapStudent[2] = "two";
    mapStudent[3] = "three";
    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
}

void insertSuccess() {
    map<int, string> mapStudent;
    mapStudent.insert(map<int, string>::value_type (1, "one"));
    pair<map<int, string>::iterator, bool> Inssert_Pair;
    Inssert_Pair = mapStudent.insert(pair<int, string>(1, "two"));
    if (Inssert_Pair.second == true) {
        cout << "insert successfully" << endl;
    } else {
        cout << "insert failed" << endl;
    }
    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter->first << " " << iter->second << endl; 
    }
}

void reVisit() {
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent[3] = "three";

    map<int, string>::reverse_iterator reIter;
    for (reIter = mapStudent.rbegin(); reIter != mapStudent.rend(); reIter++) {
        cout << reIter->first << " " << reIter->second << endl;
    }
}

void arrayVisit() {
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string>(1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent.insert(map<int, string>::value_type (3, "three"));

    for (int i = 1; i <= mapStudent.size(); i++) {
        cout << mapStudent[i] << endl;
    }
}

// 查找元素
// count() 判断关键字是否出现，但是无法定位出现的位置
// count 的返回值：出现返回1，否则返回0
// find() 定位元素出现的位置，返回一个迭代器
// 当数据出现时，返回数据所在位置的迭代器；若没有，则返回end。

void find1() {
    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string> (1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent.insert(pair<int, string> (3, "three"));

    map<int, string>::iterator iter;
    iter = mapStudent.find(3);
    if (iter != mapStudent.end()) {
        cout << "find " << iter->second << endl;
    } else {
        cout << "not find" << endl;
    }
}

void find2() {
    // lower_bound() 函数返回查找关键字的下界
    // upper_bound() 函数返回查找关键字的上界
    // equal_range() 函数返回一个pair
    // pair中的第一个变量是 lower_bound 返回值，第二个变量是 upper_bound 返回值
    // 如果两个值相等的话，说明map中不存在这个关键字

    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string> (1, "one"));
    mapStudent.insert(map<int, string>::value_type (3, "two"));
    mapStudent.insert(pair<int, string> (5, "three"));

    map<int, string>::iterator iter;
    // 1
    iter = mapStudent.lower_bound(1);
    // cout << iter->first << endl;

    // 3
    iter = mapStudent.lower_bound(2);
    // cout << iter->first << endl;

    // 3
    iter = mapStudent.lower_bound(3);
    // cout << iter->first << endl;

    // 5
    iter = mapStudent.lower_bound(4);
    // cout << iter->first << endl;

    // 3
    iter = mapStudent.upper_bound(1);
    // cout << iter->first << endl;

    // 3
    iter = mapStudent.upper_bound(2);
    // cout << iter->first << endl;

    // 5
    iter = mapStudent.upper_bound(3);
    // cout << iter->first << endl;

    // 5
    iter = mapStudent.upper_bound(4);
    // cout << iter->first << endl;

    pair<map<int ,string>::iterator, map<int, string>::iterator> mappiter;
    mappiter = mapStudent.equal_range(2);
    if (mappiter.first == mappiter.second) {
        cout << "not find" << endl;
    } else {
        cout << "find" << endl;
    }

    mappiter = mapStudent.equal_range(3);
    if (mappiter.first == mappiter.second) {
        cout << "not find" << endl;
    } else {
        cout << "find" << endl;
    }
}

void delete1() {
    // erase()
    // iterator erase(iterator it)  通过一个条目对象删除
    // iterator erase(iterator first, iterator last)  删除一个范围 [first, last)
    // size_type erase(const Key& key)  通过关键字删除
    // clear() 相当于 enumMap.erase(enumMap.begin(), enumMap.last()) 

    map<int, string> mapStudent;
    mapStudent.insert(pair<int, string> (1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent.insert(pair<int, string> (3, "three"));

    map<int, string>::iterator iterD;
    iterD = mapStudent.find(1);

    mapStudent.erase(iterD);

    map<int, string>::iterator iter;
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter-> first << " " << iter->second << endl;
    }
    cout << " " << endl;

    mapStudent.insert(pair<int, string> (1, "one"));
    mapStudent.insert(pair<int, string> (4, "four"));
    mapStudent.insert(pair<int, string> (5, "five"));

    map<int, string>::iterator iterD2;
    iterD2 = mapStudent.find(3);
    mapStudent.erase(iterD, iterD2);

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter-> first << " " << iter->second << endl;
    }
    cout << " " << endl;

    mapStudent.insert(pair<int, string> (1, "one"));
    mapStudent.insert(map<int, string>::value_type (2, "two"));
    mapStudent.insert(pair<int, string> (3, "three"));

    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter-> first << " " << iter->second << endl;
    }
    cout << " " << endl;

    mapStudent.clear();
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter-> first << " " << iter->second << endl;
    }

}

typedef struct student {
    int sID;
    string name;
    bool operator < (student const& _A) const {
        if (sID < _A.sID) {
            return true;
        }
        if (sID == _A.sID) {
            return name.compare(_A.name) < 0;
        }
        return false;
    }
}StudentInfo, *PStudentInfo;


// map 中的 sort 问题
// map 中的元素是自动按照 key 的升序进行排序，所以不能对 map 使用 sort 函数
// STL 中默认使用 < 来排序
// 若 key 是一个结构体，就会涉及到一个排序问题，因为它没有小于号操作
// 在结构体中重载操作符
void compare1() {
    int studentSize;
    map<StudentInfo, int> mapStudent;
    map<StudentInfo, int>::iterator iter;
    StudentInfo studentinfo;
    studentinfo.sID = 33;
    studentinfo.name = "student one";
    mapStudent.insert(pair<StudentInfo, int> (studentinfo, 90));
    studentinfo.sID = 1;
    studentinfo.name = "student two";
    mapStudent.insert(pair<StudentInfo, int> (studentinfo, 88));
    for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
        cout << iter->first.sID << " " << iter->first.name << " " << iter->second << endl;
    }
}

