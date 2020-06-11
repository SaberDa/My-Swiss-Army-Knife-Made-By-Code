#include <iostream>
#include <string>

using namespace std;

bool compare(const string& s, const string& t) {
    if (s.size() != t.size()) {
        return s.size() < t.size();
    }
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < t[i]) return true;
        else if (s[i] > t[i]) return false;
    }
    return true;
}