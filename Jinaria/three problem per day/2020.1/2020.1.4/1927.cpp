#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>> heap;
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