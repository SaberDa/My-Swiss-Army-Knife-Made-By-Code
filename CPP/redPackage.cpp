#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <ctime>

#define random(x)(rand()%x)

using namespace std;

int main() {

    int i, number;
    int best;
    float total;

    cout << "请输入红包金额" << endl;
    total = 100;
    // cin >> total;
    cout << "100" << endl;
    cout << "请输入人数" << endl;
    number = 10;
    cout << "10" << endl;
    // cin >> number;

    // 生成随机数
    srand((unsigned)time(nullptr));

    // 成员数组
    float people[1000]; // 设置最多100人抢
    float money[1000]; // 设置红包金额
    // 初始化人员和钱包
    float sumPeople = 0;
    float sumMoney = 0;
    // 设置手气最佳
    int max = 0;

    // 设置每人权重
    for (int i = 0; i < number; i++) {
        people[i] = random(100);
        // people[i] = rand() % 100;
        if (people[i] > max) {
            max = people[i];
            best = i;
        }
        sumPeople += people[i];
    }

    // 根据每人的权重分配红包金额
    for (int i = 0; i < number - 1; i++) {
        // 分配金额
        money[i] = people[i] / sumPeople * total;
        // 保留两位小数
        sumMoney += round(money[i] * 100) / 100.0;
        cout << "第" << setiosflags(ios::right) 
             << setw(3) << i + 1 << "个人的红包是：" 
             << setiosflags(ios::right) << setw(6)
             << setiosflags(ios::fixed) 
             << setprecision(2)
             << round(money[i] * 100) / 100.0
             << endl;
        if (best == i) {
            cout << "（手气最佳）" << endl;
        } else {
            cout << endl;
        }
    }

    // 最后一人的红包金额等于total减去前面所有人的金额和
    cout << "第" << setiosflags(ios::right) 
         << setw(3) << number << "个人的红包是："
         << setiosflags(ios::right) << setw(6) 
         << setiosflags(ios::right)
         << setprecision(2)
         << round((total -sumMoney) * 100) / 100.0
         << endl;
    if (best == number-1) {
        cout << "（手气最佳）" << endl;
    } else {
        cout << endl;
    }

    return 0;

}

// 命名空间 iomanip
// setiosflags 执行由参数指定区域内的动作
// setprecision 设定浮点数精度
// setw(n) 设域宽为n个字符
// setfill(c) 设填充字符为c 
// setioflags(ios::fixed) 固定的浮点显示 
// setioflags(ios::scientific) 指数表示 
// setiosflags(ios::left) 左对齐 
// setiosflags(ios::right) 右对齐 
// setiosflags(ios::skipws 忽略前导空白 
// setiosflags(ios::uppercase) 16进制数大写输出 
// setiosflags(ios::lowercase) 16进制小写输出 
// setiosflags(ios::showpoint) 强制显示小数点 
// setiosflags(ios::showpos) 强制显示符号 

