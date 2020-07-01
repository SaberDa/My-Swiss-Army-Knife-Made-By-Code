#include <vector>
#include <numeric>

using namespace std;

size_t find(vector<size_t>& parents, size_t c) {
	return (parents[c] == c) ? parents[c] : find(parents, parents[c]);
}

size_t mainFunction(vector<vector<size_t>> nums) {
	int m = nums.size();
	// The vector size must be the sum + 1
	vector<size_t> parents(m + 1);
	// Assignment value to vector
	iota(parents.begin(), parents.end(), 0);
	// Do operations in nums
	for (int i = 0; i < nums.size(); i++) {
		// This is the Union() operation
		// Find the root1
		size_t root1 = find(parents, nums[i][0]);
		// Find the root2
		size_t root2 = find(parents, nums[i][1]);
		// If root1 == root2, do operations according to problem
		// Else if root1 != root2, put the root2 as the value of parents[root1]
		if (root1 != root2) parents[root1] = root2;
	}
	// Do other operations
}