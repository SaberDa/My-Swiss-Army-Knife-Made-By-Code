#include <iostream>
#include <vector>

using namespace std;

class RotateMatrix {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 1; j < n-1; j++) {
                int topLeft = matrix[i][j];
                int topRight = matrix[j][n-i];
                int bottomLeft = matrix[n-j][i];
                int bottomRight = matrix[n-i][n-j];
                matrix[i][j] = bottomLeft;
                matrix[j][n-i] = topLeft;
                matrix[n-i][n-j] = topRight;
                matrix[n-j][i] = bottomRight;
            }
        }
    }
};