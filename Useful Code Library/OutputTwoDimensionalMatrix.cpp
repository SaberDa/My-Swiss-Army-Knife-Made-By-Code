#include <iostream>
#include <vector>

using namespace std;

class Output2DimensionalMatrix {
private:
    vector<vector<int>> nums;
public:
    void output2DMatrix(vector<vector<int>> nums) {
        if (nums.empty()) {
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                cout << nums[i][j] << endl;
            }
        }
    }

};