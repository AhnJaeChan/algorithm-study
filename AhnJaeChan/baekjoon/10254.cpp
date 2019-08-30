//
// Created by 안재찬 on 2019-08-29.
//

#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

class Point {
public:
  int x;
  int y;

  Point() : x(0), y(0) {};

  Point(int x, int y) : x(x), y(y) {};

  static double euclidean_distance(const Point &p1, const Point &p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
  }

  friend ostream &operator<<(ostream &os, const Point &p);
  friend istream &operator>>(istream &is, Point &p);
};

ostream &operator<<(ostream &os, const Point &p) {
  os << p.x << " " << p.y << " ";
  return os;
}

istream &operator>>(istream &is, Point &p) {
  is >> p.x >> p.y;
  return is;
}

Point p0; // For sorting;

int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

  if (val == 0) return 0;  // colinear
  return (val > 0) ? 1 : 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2) {
  auto *p1 = (Point *) vp1;
  auto *p2 = (Point *) vp2;

  int o = orientation(p0, *p1, *p2);
  if (o == 0) {
    return (Point::euclidean_distance(p0, *p2) >= Point::euclidean_distance(p0, *p1)) ? -1 : 1;
  }

  return (o == 2) ? -1 : 1;
}

Point next_to_top(stack<Point> &S) {
  Point p = S.top();
  S.pop();
  Point res = S.top();
  S.push(p);
  return res;
}

void convex_hull(Point points[], int n) {
  int min_idx = 0;

  for (int i = 1; i < n; i++) {
    if (points[i].y < points[min_idx].y) {
      min_idx = i;
    } else if (points[i].y == points[min_idx].y) {
      if (points[i].x < points[min_idx].x) {
        min_idx = i;
      }
    }
  }

  swap(points[0], points[min_idx]);
  p0 = points[0]; // Global variable, must be called before sorting since it is used inside the compare function

  qsort(&points[1], n - 1, sizeof(Point), compare);

  int m = 1;
  for (int i = 1; i < n; i++) {
    while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0) {
      i++;
    }
    points[m] = points[i];
    m++;
  }

  if (m < 3) {
    // Can't execute convex hull
    return;
  }

  stack<Point> S;
  S.push(points[0]);
  S.push(points[1]);
  S.push(points[2]);

  for (int i = 3; i < m; i++) {
    while (orientation(next_to_top(S), S.top(), points[i]) != 2) {
      S.pop();
    }
    S.push(points[i]);
  }

  Point outer_points[S.size()];

  m = 0;
  while (!S.empty()) {
    outer_points[m++] = S.top();
    S.pop();
  }

  // Find max distance
  double max_distance = 0;
  pair<Point, Point> end_points;

  for (int i = 0; i < m; i++) {
    Point p = outer_points[i];
    for (int j = i + 1; j < m; j++) {
      double distance = Point::euclidean_distance(p, outer_points[j]);
      if (max_distance < distance) {
        end_points.first = p;
        end_points.second = outer_points[j];
        max_distance = distance;
      }
    }
  }

  cout << end_points.first << end_points.second << endl;
}

int main(int argc, char *argv[]) {
  int T;

  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int n;

    cin >> n;

    Point points[n];
    for (int i = 0; i < n; i++) {
      cin >> points[i];
    }

    convex_hull(points, n);
  }

  return 0;
}