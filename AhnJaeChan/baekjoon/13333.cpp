//
// Created by 안재찬 on 09/09/2019.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

  int N;
  cin >> N;

  int nums[N];
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  sort(nums, nums + N);

  for (int i = 0; i < N; i++) {
    int idx = lower_bound(nums, nums + N, i) - nums;

    if (N - idx >= i && nums[N - i - 1] <= i) {
      cout << i << endl;
      return 0;
    }
  }

  cout << N << endl;

  return 0;
}