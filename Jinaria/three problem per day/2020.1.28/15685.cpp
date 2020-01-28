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
    Point& operator-(const Point &p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }
};

class Curve {
private:
    vector<Point> rotate(Point stan, vector<Point>& points) {
        vector<Point> ret;
        for (Point& p : points) {

        }
    }
public:
    Point point;
    int d, g;
    Curve() :point(0, 0), d(0), g(0) {

    }
    Curve(int x, int y, int d, int g) :point(x, y), d(d), g(g) {

    }

};

int main() {
    int N;
    scanf("%d", &N);
    vector<Curve> curves(N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d %d %d", curves[i].x, curves[i].y, curves[i].d, curves[i].g);


}