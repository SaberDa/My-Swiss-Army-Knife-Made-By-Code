#include <vector>

using namespace std;

string morseCodeGen(string input) {
    vector<string> table{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string res = "";
    for (auto c : input) res += table[c - 'a'];
    return res;
}