#include <iostream>

using namespace std;

int main() {

    // array直接初始化一个char数组是特殊的
    // 这种初始化要记得字符数组是以一个null结尾的

    // 初始化， 没有null
    char a1[] = {'C', '+', '+'};
    // 初始化，有null
    char a2[] = {'C', '+', '+', '\0'};
    // null终止符自动添加
    char a3[] = "C++";
    // 报错，因为没有null的位置，越界
    const char a4[6] = "runoob";
    const char a5[7] = "runoob";

    // 一些初始化注意事项
    int array[100];     // 静态初始化，定义了数组array，并且没有进行初始化
    int array2[100] = {1, 2};   // 静态初始化，定义并且初始化
    int* array3 = new int[100];
    delete []array3;            // 动态初始化，分配了长度为100的数组array
    int* array4 = new int[100]{1, 2}; 
    delete []array4;            // 动态初始化，为长度100的数组初始化前两个元素

    // 数组在使用时，是可以是一个含有变量的表达式
    // 但是声明数组时必须用常量表达式
    // 合法
    const int a = 19;
    int a6[a];
    // 合法
    const int b = 10;
    int a7[b+5];
    // 不合法
    int c = 10;
    int a8[c];

    

    return 0;
}

// 数组初始化可以使用聚合方法
// 但是赋值时不可以使用聚合方法
// 合法写法
int array[] = {1, 2, 3};
// 非法写法
int array2[];
int initArr() {

    array2[] = {1, 2, 3};
    return 0;
}

