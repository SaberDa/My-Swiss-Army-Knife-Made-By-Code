#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/*
 * regex_match 用于匹配字符串和正则表达式,有很多不同的重载形式
 * 最简单的一个形式就是传入 string 以及一个 regex 进行匹配
 * 当匹配成功时，会返回 true，否则返回 false。
*/

void regex_with_regexmatch(vector<string> &strs) {
    regex txt_regex("[a-z]+\\.txt");
    for (auto s : strs) {
        cout << s << " : " << regex_match(s, txt_regex) << endl;
    }
}

/*
 * 另一种常用的形式就是依次传入 string, smatch, regex 三个参数
 * 其中 smatch 的本质其实是 match_results
 * 
 * 在标准库中，smatch 被定义为了 match_results<string::const_iterator>
 * 也就是一个子串迭代器类型的 match_results
 * 
 * 使用 smatch 可以方便的对匹配的结果进行获取
*/

void regex_with_smatch(vector<string> &strs) {
    regex base_regex("([a-z]+)\\.txt");
    smatch base_match;
    for (auto s : strs) {
        if (regex_match(s, base_match, base_regex)) {
            if (base_match.size() == 2) {
                string base = base_match[1].str();
                cout << "sub-match[0]: " << base_match[0].str() << endl;
                cout << s << " sub-match[1]: " << base << endl;
            }
        }
    }
}


int main() {

    vector<string> strs = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};

    cout << "Use regex_match()" << endl;
    regex_with_regexmatch(strs);

    cout << endl;

    cout << "Use smatch so that we can get the regex content" << endl;
    regex_with_smatch(strs);

    return 0;
}