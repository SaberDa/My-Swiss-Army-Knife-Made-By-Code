#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLTS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp;
    for (auto x : nums) {
        int pos = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        if (pos == dp.size()) dp.push_back(x);
        else dp[pos] = x;
    }
    return dp.size();
}
