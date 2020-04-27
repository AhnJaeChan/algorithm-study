#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int n[1000001];

int find(int a) {
    if (a == n[a])
        return a;
    n[a] = find(n[a]);
    return n[a];
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        n[a] = b;
    }
}

int plan[1001];

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i <= N; ++i)
        n[i] = i;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int a;
            scanf("%d", &a);
            if (a) {
                unionSet(i, j);
            }
        }
    }
    for (int i = 0; i < M; ++i)
        scanf("%d", &plan[i]);

    for (int i = 1; i < M; ++i) {
        if (find(plan[i - 1]) != find(plan[i])) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");



    return 0;
}