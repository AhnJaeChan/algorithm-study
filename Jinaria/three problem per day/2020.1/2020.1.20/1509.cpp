#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool d[2501][2501];
int dp[2501];

int main() {
    char input[2501];
    scanf("%s", input);
    string pel = input;
    int ans = 0;
    for (int i = 1; i <= pel.size(); ++i)
        d[i][i] = true;
    for (int i = 1; i <= pel.size() - 1; ++i)
        if (pel[i - 1] == pel[i])
            d[i][i + 1] = true;

    for (int len = 3; len <= pel.size(); ++len) {
        for (int i = 1; i <= pel.size() - len + 1; ++i) {
            if (d[i + 1][i + len - 2] && pel[i - 1] == pel[i + len - 2])
                d[i][i + len - 1] = true;
        }
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= pel.size(); ++i) {
        int mindp = 1234567890;
        for (int j = 0; j < i; ++j) {
            if(d[j + 1][i])
                mindp = min(mindp, dp[j]);
        }
        dp[i] = mindp + 1;
    }
    ans = dp[pel.size()];
    printf("%d\n", ans);
}