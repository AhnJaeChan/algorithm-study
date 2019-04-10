#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


bool match(string &w, string &s) {
    string::size_type pos = 0;

    while (pos < w.size() && pos < s.size() && (w[pos] == '?' || w[pos] == s[pos])) {
        ++pos;
    }

    if (pos == w.size()) {
        return pos == s.size();
    }

    if (w[pos] == '*') {
        for (int offset = 0; pos + offset <= s.size(); ++offset) {
            string new_w = w.substr(pos + 1);
            string new_s = s.substr(pos + offset);

            if (match(new_w, new_s)) {
                return true;
            }
        }
    }

    return false;
}

int main() {


    int C;
    string W, S;
    int n;

    cin >> C;

    for (int i = 0; i < C; ++i) {
        cin >> W >> n;

        for (int j = 0; j < n; ++j) {
            cin >> S;

            if (match(W, S)) {
                cout << S << endl;
            }
        }
    }

    return 0;
}
