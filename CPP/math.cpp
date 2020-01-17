#include <cmath>
#include <iostream>

using namespace std;

/*
* double cos(double) 
* double sin(double)
* double tan(double)
* double log(double)
* double pow(double x, double y)   x^y
* double hypot(double x, double y)    返回以x，y为直角边的斜边长
* double sqrt(double) 平方根
* int abs(int) 绝对值
* double fabs(double) 浮点数的绝对值
* double floor(double) 向下取整
*/

int main() {
    int i = -10;
    long l = 100000;
    float f = 3.14;
    double d = 20.2111;

    cout << abs(i) << endl;
    cout << hypot(3, 4) << endl;
    cout << floor(f) << endl;
    cout << sqrt(16) << endl;
    
    return 0;
}