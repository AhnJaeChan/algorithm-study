#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> heap;
    vector<int> v;
    int n, t;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (t == 0) {
            if (heap.empty()) {
                v.push_back(0);
            }
            else {
                v.push_back(heap.top());
                heap.pop();
            }
        }
        else {
            heap.push(t);
        }
    }
    for (int i : v) {
        printf("%d\n", i);
    }
}