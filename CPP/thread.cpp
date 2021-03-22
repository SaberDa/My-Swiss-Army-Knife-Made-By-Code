#include <iostream>
#include <thread>

using namespace std;

void foo() {
    cout << "hello" << endl;
}

int main() {

    thread t(foo);
    t.join();

    return 0;
}