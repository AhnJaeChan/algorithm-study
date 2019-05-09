#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int cache[15] = { -1, };
int cnt = 0;

int def(int idx, vector<pair<int, int> > &consult) {
    if (cache[idx] != -1) {
        return cache[idx];
    }
    int i = idx;
    int max = 0;
    int sum = 0;
    while (i < consult.size()) {
        int cur = i++;
        int next = cur + consult[cur].first;
        if (next > consult.size()) continue;
        sum = consult[cur].second + def(next, consult);
        if (sum > max) max = sum;
    }
    cache[idx] = max;
    return max;
}

int main() {
    int N;
    cin >> N;
    fill_n(cache, 15, -1);
    vector<pair<int, int> > consult(N, { 0, 0 });
    for (auto &a : consult) {
        cin >> a.first >> a.second;
    }
    int result = def(0, consult);
    cout << result << endl;
    return 0;
}