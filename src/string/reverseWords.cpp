#include <iostream>
#include <string>

using namespace std;

void reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}

void removeExtraSpaces(string& s) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
        if (s[fastIndex] != ' ') {
            if (slowIndex > 0) s[slowIndex++] = ' ';
            while (fastIndex < s.size() && s[fastIndex] != ' ') {
                s[slowIndex++] = s[fastIndex++];
            }
        }
    }
    s.resize(slowIndex);
}

string reverseWords(string s) {
    removeExtraSpaces(s);
    reverse(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            reverse(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main() {
    string s = "  the sky is blue";
    string result = reverseWords(s);
    cout << result << endl;
}