//
// Created by 안재찬 on 09/09/2019.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cards[1001];
int dp[1001][1001][2];

enum Turn {
  GEUN_WOO = 0,
  MYOUNG_WOO = 1
};

int find_max(int i, int j, Turn turn) {
  if (dp[i][j][turn] != -1) {
    return dp[i][j][turn];
  }

  if (i == j) {
    dp[i][j][turn] = Turn::GEUN_WOO == turn ? cards[i] : 0;
    return dp[i][j][turn];
  }

  if (Turn::GEUN_WOO == turn) {
    dp[i][j][turn] = max(find_max(i + 1, j, Turn::MYOUNG_WOO) + cards[i],
                         find_max(i, j - 1, Turn::MYOUNG_WOO) + cards[j]);
  } else {
    dp[i][j][turn] = min(find_max(i + 1, j, Turn::GEUN_WOO), find_max(i, j - 1, Turn::GEUN_WOO));
  }
  return dp[i][j][turn];
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
      cin >> cards[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << find_max(1, N, Turn::GEUN_WOO) << endl;
  }

  return 0;
}