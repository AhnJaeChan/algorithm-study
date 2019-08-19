#include <iostream>
#include <vector>

using namespace std;

int fibo[45] = {
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657,
    46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352,
    24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733,
};

vector<int> s;

int main() {
  int T;

  cin >> T;
  for (int test_case = 0; test_case < T; ++test_case) {
    int N;
    cin >> N;

    int idx = 44;
    int sum = 0;

    s.clear();
    while (sum != N) {
      while (fibo[idx--] > N - sum);

      s.push_back(fibo[idx + 1]);
      sum += fibo[idx + 1];
    }

    for (auto i = s.rbegin(); i != s.rend(); ++i) {
      cout << *i << " ";
    }
    cout << endl;
  }

  return 0;
}