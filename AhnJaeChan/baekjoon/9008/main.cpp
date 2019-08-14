#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
  int key;
  int p1, p2;

  Point(int key, int p1, int p2) {
    this->key = key;
    this->p1 = p1;
    this->p2 = p2;
  }

  bool operator<(const Point &comp) const {
    // sort by p1, if p1 is same -> sort by p2 (ascending)
    return (p1 != comp.p1) ? (p1 < comp.p1) : (p2 < comp.p2);
  }

  friend ostream &operator<<(std::ostream &os, const Point &point) {
    return os << point.p1 << ", " << point.p2 << "(" << point.key << ")";
  }
};

const int MAX_POINTS = 10000;

int T, N;
vector<Point> vpoints;
vector<Point> hpoints;
pair<int, int> connection[MAX_POINTS];

bool solve() {
  // Check each verticals
  for (int i = 0; i < N; i += 2) {
    // Check for horizontal intersection
    for (int j = 0; j < N; j += 2) {
      if (vpoints[i].p2 < hpoints[j].p1 && hpoints[j].p1 < vpoints[i + 1].p2) {
        if (hpoints[j].p2 < vpoints[i].p1 && vpoints[i].p1 < hpoints[j + 1].p2) {
          return false;
        }
      }
    }
  }

  for (int i = 0; i < N; i += 2) {
    if (vpoints[i].p1 != vpoints[i + 1].p1 || hpoints[i].p1 != hpoints[i + 1].p1) {
      return false;
    }
  }

  // index = key
  // first = vertical connection index
  // second = horizontal connection index
  for (int i = 0; i < N; i += 2) {
    connection[vpoints[i].key].first = vpoints[i + 1].key;
    connection[vpoints[i + 1].key].first = vpoints[i].key;

    connection[hpoints[i].key].second = hpoints[i + 1].key;
    connection[hpoints[i + 1].key].second = hpoints[i].key;
  }

  // Start from key 0's vertical connection and follow the path
  // until it comes back to index 0. If the count is the same
  // as the number of points, it means that the line connection
  // has traversed around all the points. If not, there are
  // at least 2 independent polygons.
  int count = 1;
  int key = connection[0].first;

  while (key != 0) {
    key = (count % 2 == 0) ? connection[key].first : connection[key].second;
    count++;
  }

  return count == vpoints.size();
}

int main() {
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    cin >> N;

    vpoints.clear();
    hpoints.clear();

    int x, y;
    for (int i = 0; i < N; ++i) {
      cin >> x >> y;
      vpoints.emplace_back(Point(i, x, y));
      hpoints.emplace_back(Point(i, y, x));
    }

    if (N % 2 == 1) {
      cout << "NO" << endl;
      continue;
    }

    sort(vpoints.begin(), vpoints.end());
    sort(hpoints.begin(), hpoints.end());

    cout << (solve() ? "YES" : "NO") << endl;
  }

  return 0;
}