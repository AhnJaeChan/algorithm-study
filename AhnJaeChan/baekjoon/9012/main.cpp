#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int i = 0; i < T; ++i) {
    string input;
    cin >> input;

    int cnt = 0;
    for (char &c: input) {
      if (c == '(') {
        cnt++;
      } else {
        cnt--;
      }

      if (cnt < 0) {
        break;
      }
    }

    cout << (cnt == 0 ? "YES" : "NO") << endl;
  }

  return 0;
}