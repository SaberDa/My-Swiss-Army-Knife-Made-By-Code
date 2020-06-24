#include <iostream>
#include <vector>

using namespace std;

// nums's value are either 1 or 0
// eg: nums = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
int binaryToInteger(vector<int> nums) {
    int res = 0;
    for (auto x : nums) {
        res <<= 1;
        res |= x;
    }
    return res;
}

int main() {
    vector<int> nums = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    cout << binaryToInteger(nums) << endl;
    return 0;
}