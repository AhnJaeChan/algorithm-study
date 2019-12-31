#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>

using namespace std;

vector<pair<int, int>> arr;

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }
        int result = 1;
        for (auto k : m) {
            result *= (k.second + 1);
        }
        result--;
        printf("%d\n", result);
    }
}