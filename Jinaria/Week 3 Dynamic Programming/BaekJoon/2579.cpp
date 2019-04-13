#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int stair_num;
    cin >> stair_num;
    vector<int> score(stair_num);
    vector<vector<int> > dp(stair_num + 1, vector<int>(2));

    for (auto i = score.begin(); i != score.end(); i++)
        cin >> *i;

    for (int i = 1; i < stair_num + 1; i++) {

        if (i == 1) {
            dp[i][0] = score[i - 1];
            dp[i][1] = -1;
        }
        else if (i == 2) {
            dp[i][0] = dp[i - 1][0] + score[i - 1];
            dp[i][1] = score[i - 1];
        }
        else {
            dp[i][0] = dp[i - 1][1] + score[i - 1];
            dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + score[i - 1];
        }
    }
    int ret = max(dp[stair_num][0], dp[stair_num][1]);
    cout << ret << endl;
}