#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &v[i].second, &v[i].first);
    }

    sort(v.begin(), v.end());
    int curEndTime = 0, result = 0;
    for (auto p : v) {
        if (p.second >= curEndTime) {
            result++;
            curEndTime = p.first;
        }
    }
    printf("%d\n", result);
}