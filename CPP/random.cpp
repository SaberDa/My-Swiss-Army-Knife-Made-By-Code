
// rand() 
// 返回一个伪随机数
// srand() 
// 在生成随机数之前一定要先调用srand函数


// rand() 
// rand生成随机数的范围
// 在标准的C库中，rand()可以生成 0~RAND_MAX之间的一个随机数
// 其中 RAND_MAX 是 stdlib.h 中定义的一个整数，它与系统有关，至少为32767

// srand() 
// srand函数是随机数发生器的初始化函数
// srand会提供一个种子，这个种子会对应一个随机数
// 如果使用相同的种子，后面的rand函数会出现一样的随机数
// 为了防止随机数的重复，常常使用系统时间来初始化，即使用time函数来获得系统时间
// time的返回值从 00:00:00 GMT, january 1, 1970到现在所持续的秒数
// 然后将time_t型数据转化为 unsigned 再传递给srand
// 或者传入一个空指针nullptr

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main1() {
    int i, j;
    
    // 设置种子
    srand((unsigned)time(nullptr));

    // 生成10个随机数
    for (int i = 0; i < 10; i++) {
        j = rand();
        cout << j << endl;
    }

    return 0;
}



// 取一定范围的随机数
// 可以在宏中定义一个函数
#define randomOne(x)(rand()%x)
// 或者定义从m到n之间的随机数
#define randomRange(m, n)(rand()%(n-m+1)+m)

int main() {
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 10; i++) {
        cout << randomRange(20,50) << endl;
    }
    return 0;
}


