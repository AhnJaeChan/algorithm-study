//
// Created by 안재찬 on 2019-08-29.
//
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  int T;

  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int N, W, H;

    cin >> H >> W >> N;

    int row = (N - 1) % H;
    int col = (N - 1) / H;

    int room_number = (row + 1) * 100 + (col + 1);

    cout << room_number << " ";
  }

  return 0;
}
