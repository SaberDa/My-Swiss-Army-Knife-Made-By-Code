#include <iostream>
#include <string>

#include "Connect.hpp"

class A {
signals:
    Signal<> m_s1;      // Signals without parameter
    Signal<std::string> m_s2;
    Signal<int, std::string> m_s3;
public:
    void start() {
        emit m_s1();
        emit m_s2("Hello World!");
        emit m_s3(404, "Hello World!");
    }
};

class B {
public:
    void func1() {
        std::cout << "func1" << std::endl;
    }

    void func2(const std::string& str) {
        std::cout << str << std::endl;
    }

    void func3(int n, const std::string& str) {
        std::cout << n << " " << str << std::endl;
    }
};

void func(const std::string& str) {
    std::cout << "func " << str << std::endl; 
}

int main() {
    A a;
    B b;

    // Bind the signal with slot
    connect(&a, m_s1, std::bind(&B::func1, &b));
    connect(&a, m_s2, std::bind(&B::func2, &b, std::placeholders::_1));
    connect(&a, m_s3, std::bind(&B::func3, &b, std::placeholders::_1, std::placeholders::_2));
    connect(&a, m_s2, std::bind(func, std::placeholders::_1));
    connect(&a, m_s2, [](const std::string& str)
            {
                std::cout << "lambda str: " << str << std::endl;
            });

    a.start();

    /* Output:
     * func1
     * Hello World!
     * func Hello World!
     * lambda str: Hello World!
     * 404 Hello World!
     */

    return 0;
}