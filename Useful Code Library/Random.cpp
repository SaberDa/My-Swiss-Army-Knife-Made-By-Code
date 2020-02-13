#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

class Random {
public:
    // Make a range of random
    #define randomOne(range)(rand()%range)
    // Make the random between the range of from lowBound to highBound
    #define randomRange(lowBound, highBound)(rand()%(highBound-lowBound+1)+lowBound)
    vector<int> generateRandom(int lowBound, int highBound, int number) {

        vector<int> res;
        srand((unsigned)time(nullptr));
        for (int i = 0; i < number; i++) {
            res.push_back(randomRange(lowBound, highBound));
        }
        return res;
    }
    vector<int> generateRandom(int range, int number) {

        vector<int> res;
        srand((unsigned)time(nullptr));
        for (int i = 0; i < number; i++) {
            res.push_back(randomOne(range));
        }
        return res;
    }

};