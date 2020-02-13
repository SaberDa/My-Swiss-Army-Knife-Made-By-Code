#include <iostream>
#include <queue>
#include <functional>

using namespace std;

struct compare {
    bool operator() (int &a, int &b) const {
        return a > b;
    }
};

class MinHeap {
private:
    // Use the compare struct to build the min heap
    priority_queue<int, vector<int>, compare> pq;
    // Use the greater to build the main heap
    // Note: we should include the functional file
    // And there should be a space between the > of greater and the > of priority queue
    priority_queue<int, vector<int>, greater<int> > pqq;



};
