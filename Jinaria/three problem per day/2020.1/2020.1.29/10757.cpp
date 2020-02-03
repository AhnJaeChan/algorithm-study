#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string strplus(string &a, string &b) {
    auto ai = a.rbegin(), bi = b.rbegin();
    bool flag = false;
    stack<char> s;
    while (ai != a.rend() && bi != b.rend()) {
        int k = *ai - '0' + *bi - '0' + (flag ? 1 : 0);
        if (k > 9) {
            flag = true;
            k -= 10;
        }
        else {
            flag = false;
        }
        s.push(k + '0');
        ai++; bi++;
    }
    while (ai != a.rend()) {
        int k = *ai - '0' + (flag ? 1 : 0);
        if (k > 9) {
            flag = true;
            k -= 10;
        }
        else
            flag = false;
        s.push(k + '0');
        ai++;
    }
    while (bi != b.rend()) {
        int k = *bi - '0' + (flag ? 1 : 0);
        if (k > 9) {
            flag = true;
            k -= 10;
        }
        else
            flag = false;
        s.push(k + '0');
        bi++;
    }
    if (flag)
        s.push('1');
    string ret;
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }
    return ret;
}

char ta[10005], tb[10005];
int main() {
    scanf("%s %s", ta, tb);
    string a = ta, b = tb;
    string ans = strplus(a, b);
    printf("%s\n", ans.c_str());
}