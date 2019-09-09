//
// Created by 안재찬 on 09/09/2019.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> decimalToBase(int num, int base) {
  vector<int> ret;
  while (num > 0) {
    ret.push_back(num % base);
    num /= base;
  }
  return ret;
}

bool isPalindrome(vector<int> &encoded) {
  int sz = encoded.size();

  for (size_t i = 0; i < sz / 2; i++) {
    if (encoded[i] != encoded[sz - i - 1]) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int num;
    cin >> num;

    int result = 0;

    for (int base = 2; base <= 64; base++) {
      vector<int> encoded(decimalToBase(num, base));

      if (isPalindrome(encoded)) {
        result = 1;
        break;
      }
    }

    cout << result << endl;
  }

  return 0;
}