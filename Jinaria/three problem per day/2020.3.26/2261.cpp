#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#define MAX_NUM     1234567890

int N;
vector<pair<int, int>> points;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int func(int n, int start, int end) {
    if (n == 2) {
        return dist(points[start], points[end]);
    }
    if (n == 3) {
        return min(dist(points[start], points[end]), min(dist(points[start], points[start + 1]), dist(points[start + 1], points[end])));
    }
    int mid = (start + end) / 2;
    double stand = (points[mid].first + points[mid + 1].first) / 2;

    int d = min(func((n + 1) / 2, start, mid), func(n / 2, mid + 1, end));
    

    vector<pair<int, int>> temp;
    for (int i = start; i <= end; ++i) {
        int td = stand - points[i].first;
        if (td * td < d)
            temp.emplace_back(points[i].second, points[i].first);
    }
    sort(temp.begin(), temp.end());
    
    int ret = d;

    for (vector<pair<int, int>>::iterator it = temp.begin(); it != temp.end(); ++it) {
        
        for (int i = it - temp.begin() + 1; i < temp.size(); ++i) {
            int td = temp[i].first - it->first;
            if (td * td >= d)
                break;
            int num = dist(*it, temp[i]);
            if (num < ret) {
                ret = num;
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    points.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> points[i].first >> points[i].second;

    sort(points.begin(), points.end());

    int answer = func(N, 0, N - 1);

    cout << answer << '\n';

}