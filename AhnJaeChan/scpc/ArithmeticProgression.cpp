#include <iostream>
#include <cmath>

using namespace std;

int Answer;

uint64_t seq[100000];

uint64_t gcd(uint64_t num1, uint64_t num2) {
  if (num1 == 0 || num2 == 0) {
    return 0;
  }

  while (num2 != 0) {
    uint64_t tmp = num1 % num2;
    num1 = num2;
    num2 = tmp;
  }

  return num1;
}

// num > 0
int countDivisors(uint64_t num) {
  int cnt = 0, i;

  for (i = 1; i < sqrt(num); ++i) {
    if (num % i == 0)
      cnt += 2;
  }

  if (i * i == num) {
    cnt++;
  }

  return cnt;
}

int main(int argc, char **argv) {
  int T, test_case;
  int M;

  cin >> T;
  for (test_case = 0; test_case < T; test_case++) {

    Answer = 0;

    cin >> M;

    for (int i = 0; i < M; ++i) {
      cin >> seq[i];
    }

    uint64_t d = seq[1] - seq[0];
    for (int i = 1; i < M - 1; ++i) {
      d = gcd(d, seq[i + 1] - seq[i]);
    }

    if (d == 0) {
      Answer = 1;

      for (int i = 1; i < M; ++i) {
        if (seq[i] != seq[0]) {
          Answer = 0;
          break;
        }
      }
    } else {
      Answer = countDivisors(d);
    }

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0;
}