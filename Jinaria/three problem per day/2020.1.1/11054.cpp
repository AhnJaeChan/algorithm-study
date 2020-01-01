#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define INC     0
#define DEC     1

int lis(vector<int>& v, int start, int end, int order) {
    if (start == end) return 1;
    if (order == INC) {
        vector<int> a;
        a.push_back(v[start]);
        for (int i = start + 1; i <= end; ++i) {
            if (a.back() < v[i]) a.push_back(v[i]);
            else {
                auto k = lower_bound(a.begin(), a.end(), v[i]);
                *k = v[i];
            }
        }
        return a.size();
    }
    else {
        vector<int> a;
        a.push_back(v[start]);
        for (int i = start + 1; i <= end; ++i) {
            if (a.back() > v[i]) a.push_back(v[i]);
            else {
                auto k = lower_bound(a.begin(), a.end(), v[i], greater<int>());
                *k = v[i];
            }
        }
        return a.size();
    }
}

int bitonic(vector<int>& v, int pivot) {
    int a = lis(v, 0, pivot, INC);
    int b = lis(v, pivot, v.size() - 1, DEC);
    return a + b - 1;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int maxNum = 0;
    for (int pivot = 0; pivot < n; ++pivot) {
        maxNum = max(maxNum, bitonic(v, pivot));
    }
    printf("%d\n", maxNum);

 }