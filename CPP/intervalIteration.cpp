// 区间迭代
// 基于范围的 for 循环

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int array[5] = {1, 2, 3, 4, 5};
    for (auto &i : array) {
        cout << array[i-1] << endl;
    }

    vector<int> obj;
    obj.push_back(6);
    obj.push_back(7);
    obj.push_back(8);

    for (auto &it : obj) {
        cout << it << endl;
    }


    return 0;
}