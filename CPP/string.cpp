#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// 一些常用函数
// strcpy(s1, s2)  复制字符串 s2 到 s1
// strcat(s1, s2)  链接字符串 s2 到 s1 末尾
// strlen(s1)      返回字符串 s1 的长度
// strcmp(s1, s2)  比较，如果 s1 和 s2 是相同的，返回0；如果 s1<s2 返回值小于0，反之大于0
// strchr(s1, ch)  返回一个指针，指向字符串 s1 中字符 ch 第一次出现的位置
// strstr(s1, s2)  返回一个指针，指向字符串 s1 中字符串 s2 第一次出现的位置

void stringFunction();
void stringClass();

int main() {

    // stringFunction();
    stringClass();
    return 0;
}

void stringFunction() {
    char str1[] = "hello";
    char str2[] = "world";
    char str3[11];
    int len;

    strcpy(str3, str1);
    cout << "copy: " << str3 << endl;
    strcpy(str1, str2);
    cout << "replace: " << str1 << endl;

    strcat(str2, str3);
    cout << "link: " << str2 << endl;

    len = strlen(str2);
    cout << "str2 length: " << len << endl;

    char str[] = "saber";
    char ch1 = 'e';
    char ch2 = 'd';
    char test1[] = "ber";
    char test2[] = "da";

    if (strcmp(str, test1) < 0) {
        cout << "第一个字符串小" << endl;
    } else {
        cout << "第一个字符串大" << endl;
    }

    char *temp = strchr(str, ch1);
    cout << "1" << temp << endl;
    temp = strchr(str, ch2);
    cout << "2" << temp << endl;
}

// string类
// append() 在字符串的末尾添加字符
// find() 在字符串中查找字符
// insert() 插入字符
// length() 返回字符串长度
// replace() 替换字符串
// substr() 返回某个子串

void stringClass() {
    // string str1 = "hello";
    // string str2 = "world";
    // string str3;
    // int len;

    // //copy 
    // str3 = str1;
    // cout << str3 << endl;

    // // connect
    // str3 = str1 + str2;
    // cout << "str1 + str2" << str3 << endl;

    // // length
    // len = str3.size();
    // cout << "str3.size()" << len << endl;

    // delete
    string str = "saberda";
    int pos = str.find("er");
    cout << "pos: " << pos << endl;
    str.replace(pos, 2, "");
    cout << str << endl;

    // find sub str
    str = "saberda has a wife named saber";
    int first = str.find_first_of("d");
    int last = str.find_last_of("d");
    cout << str.substr(first+1, last-first-1) << endl;

}