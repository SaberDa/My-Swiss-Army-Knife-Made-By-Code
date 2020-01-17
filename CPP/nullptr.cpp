#include <iostream>

using namespace std;

void foo(char *);
void foo(int);

int main() {
    if (NULL == (void *)0) {
        cout << "NULL == 0" << endl;
    } else {
        cout << "NULL != 0" << endl;
    }

    foo(0);
    foo(nullptr);
    // foo(NULL);

    return 0;
}

void foo(char *ch) {
    cout << "call foo(char *)" << endl;
}

void foo(int) {
    cout << "call foo(int)" << endl;
}