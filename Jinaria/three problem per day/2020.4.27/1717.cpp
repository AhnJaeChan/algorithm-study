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

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; ++i)
        n[i] = i;
    while (M--) {
        int o, a, b;
        scanf("%d %d %d", &o, &a, &b);
        if (o) {
            if (find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else {
            unionSet(a, b);
        }
    }



    return 0;
}