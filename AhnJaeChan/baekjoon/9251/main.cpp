#include <iostream>
#include <string>

using namespace std;

inline int max(int a, int b) {
    return a > b ? a : b;
}

int lcs(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    int i, j;

    int F[len1 + 1][len2 + 1];

    for (i = 0; i <= len1; ++i) {
        F[i][0] = 0;
    }
    for (i = 0; i <= len2; ++i) {
        F[0][i] = 0;
    }

    for (i = 1; i <= len1; ++i) {
        for (j = 1; j <= len2; ++j) {
            F[i][j] = s1[i - 1] == s2[j - 1] ? F[i - 1][j - 1] + 1 : max(F[i - 1][j], F[i][j - 1]);
        }
    }

    return F[len1][len2];
}

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    cout << lcs(s1, s2) << endl;

    return 0;
}