//
// Created by 안재찬 on 2019-08-29.
//

#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
  int x;
  int y;

  Point() : x(0), y(0) {};

  Point(int x, int y) : x(x), y(y) {};

  static Point center(const Point &p1, const Point &p2) {
    return {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
  }

  static double euclidean_distance(const Point &p1, const Point &p2) {
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
  }

  static double radius(const Point &p1, const Point &p2) {
    return euclidean_distance(p1, p2) / 2;
  }

  bool is_inside(const Point &center, double radius) {
    return euclidean_distance(center, *this) <= radius;
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

int main(int argc, char *argv[]) {
  int T;

  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int n;

    cin >> n;

    Point ps, pt;
    cin >> ps >> pt;

    Point center = Point::center(ps, pt);
    double radius = Point::radius(ps, pt);

    Point p;
    for (int i = 2; i < n; i++) {
      cin >> p;

      if (!p.is_inside(center, radius)) {
        if (Point::euclidean_distance(p, ps) > Point::euclidean_distance(p, pt)) {
          pt = p;
        } else {
          ps = p;
        }

        center = Point::center(ps, pt);
        radius = Point::radius(ps, pt);
      }
    }

    cout << ps << pt << endl;
  }

  return 0;
}