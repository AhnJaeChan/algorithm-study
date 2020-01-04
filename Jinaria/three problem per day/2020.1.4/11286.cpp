#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <cmath>

using namespace std;


struct cmp {
    bool operator()(const int& a, const int& b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    int N;
    scanf("%d", &N);

    priority_queue<int, vector<int>, cmp> heap;
    int t;
    while (N--) {
        scanf("%d", &t);
        if (t == 0) {
            if (heap.empty()) {
                printf("%d\n", 0);
            }
            else {
                printf("%d\n", heap.top());
                heap.pop();
            }
        }
        else {
            heap.push(t);
        }
    }
 }