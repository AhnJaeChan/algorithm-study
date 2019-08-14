#include <iostream>
#include <vector>

using namespace std;

int T, N;

vector<pair<int, int>> vpoints;
vector<pair<int, int>> hpoints;

class Point {
  int key;
  int x, y;

  bool operator<(Point const &comp) {
    return x < comp.x;
  }
};

bool solve() {
  // Check each verticals
  for (int i = 0; i < N; i += 2) {
    int x1 = vpoints[i].first;
    int y1 = vpoints[i].second;
    int y2 = vpoints[i + 1].second;

    // Check for horizontal intersection
    for (int j = 0; j < N; j += 2) {
      if (hpoints[j].first > y1 && hpoints[j].first < y2) {
        if (hpoints[j].second < x1 && hpoints[j + 1].second > x1) {
          return false;
        }
      }
    }
  }

  for (int i = 0; i < N - 2; i += 2) {
    if (vpoints[i + 1].second == vpoints[i + 2].second || hpoints[i + 1].second == hpoints[i + 2].second) {
      return false;
    }
  }

  int cnt = 0;

  auto start = vpoints[0];
  while (cnt != vpoints.size()) {
    cnt++;
  }

  return true;
}

int main() {
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    cin >> N;

    if (N % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }

    vpoints.clear();
    hpoints.clear();

    int x, y;
    for (int i = 0; i < N; ++i) {
      cin >> x >> y;
      vpoints.emplace_back(make_pair(x, y));
      hpoints.emplace_back(make_pair(y, x));
    }

    sort(vpoints.begin(), vpoints.end());
    sort(hpoints.begin(), hpoints.end());

    for (auto p: vpoints) {
      cout << p.first << ", " << p.second << endl;
    }

    for (auto p: hpoints) {
      cout << p.first << ", " << p.second << endl;
    }

    cout << (solve() ? "YES" : "NO") << endl;
  }

  return 0;
}