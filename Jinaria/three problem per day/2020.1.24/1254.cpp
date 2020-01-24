#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool d[1001][2001];

int main() {
    char S[1001];
    scanf("%s", S);
    string str = S;

    for (int i = 0; i < str.size(); ++i)
        d[i][i] = true;
    for (int i = 0; i < str.size() - 1; ++i)
        if (str[i] == str[i + 1])
            d[i][i + 1] = true;

    for (int len = 3; len <= str.size(); ++len) {
        for (int i = 0; i < str.size() - len + 1; ++i) {
            if (str[i] == str[i + len - 1] && d[i + 1][i + len - 2])
                d[i][i + len - 1] = true;
        }
    }
    if (d[0][str.size() - 1]) {
        printf("%d\n", str.size());
        return 0;
    }
    int ans = str.size();
    for (int i = 1; i < str.size(); ++i) {
        ans++;
        if (d[i][str.size() - 1])
            break;
    }
    printf("%d\n", ans);
}