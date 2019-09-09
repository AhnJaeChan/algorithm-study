//
// Created by 안재찬 on 09/09/2019.
//
#include <iostream>
#include <algorithm>

using namespace std;

int costs[501];
int sum[501];
int dp[501][501];

int min_cost(int i, int j) {
  if (i == j) {
    return 0;
  }

  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  for (int k = i; k < j; k++) {
    int cost = min_cost(i, k) + min_cost(k + 1, j) + sum[j] - sum[i - 1];
    if (dp[i][j] == -1 || dp[i][j] > cost) {
      dp[i][j] = cost;
    }
  }
  return dp[i][j];
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int K;
    cin >> K;

    sum[0] = 0;

    for (int i = 1; i <= K; i++) {
      cin >> costs[i];
      sum[i] = sum[i - 1] + costs[i];
    }

    for (auto &l: dp) {
      fill_n(l, 501, -1);
    }

    cout << min_cost(1, K) << endl;
  }

  return 0;
}