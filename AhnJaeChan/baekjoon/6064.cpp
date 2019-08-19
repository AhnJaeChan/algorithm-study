//
// Created by 안재찬 on 2019-08-19.
//
#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int solve(int M, int N, int x, int y) {
  int last_year = lcm(M, N);

  int current_year = x;
  int base = y % N;

  while (current_year <= last_year) {
    if (current_year % N == base) {
      return current_year;
    }
    current_year += M;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    cout << solve(M, N, x, y) << endl;
  }
  return 0;
}