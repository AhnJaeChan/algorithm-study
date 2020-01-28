#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x, y;
    Point() :x(0), y(0) {

    }
    Point(int x, int y) : x(x), y(y) {

    }
};

class Curve {
private:
    void rotate(vector<Point>& points, vector<Point> &ret, int g) {
        ret = points;
        for (int i = 0; i < g; ++i) {
            Point stan = *ret.rbegin();
            for (int i = ret.size() - 2; i >= 0; --i) {
                ret.emplace_back(ret[i].y - stan.y + stan.x, ret[i].x - stan.x + stan.y);
            }
        }
    }
public:
    Point point;
    int d, g;
    vector<Point> curve_point;
    Curve() :point(0, 0), d(0), g(0) {

    }
    Curve(int x, int y, int d, int g) :point(x, y), d(d), g(g) {
        
    }
    void calculate() {
        vector<Point> points;
        points.push_back(point);
        switch (d) {
        case 0:
            points.emplace_back(point.x + 1, point.y);
            break;
        case 1:
            points.emplace_back(point.x, point.y - 1);
            break;
        case 2:
            points.emplace_back(point.x - 1, point.y);
            break;
        case 3:
            points.emplace_back(point.x, point.y + 1);
            break;
        }
        rotate(points, curve_point, g);
    }
};

bool check[101][101];

#define MASK        0b1111

int main() {
    int N;
    scanf("%d", &N);
    vector<Curve> curves(N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d %d %d", &curves[i].point.x, &curves[i].point.y, &curves[i].d, &curves[i].g);

    for (Curve& curve : curves) {
        curve.calculate();
        for (Point& p : curve.curve_point) {
            check[p.y][p.x] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            int bit = 0;
            for (int k = 0; k < 4; ++k) {
                if (check[j + k / 2][i + k % 2])
                    bit |= (1 << k);
            }
            if (bit == MASK)
                ans++;
        }
    }
    printf("%d\n", ans);
}