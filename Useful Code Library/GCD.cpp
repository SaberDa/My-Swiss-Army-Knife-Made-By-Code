#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return GCD(b, a % b);
}