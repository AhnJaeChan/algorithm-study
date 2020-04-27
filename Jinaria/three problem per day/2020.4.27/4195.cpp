#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <utility>

using namespace std;

int N, M;
int n[200005];
int len[200005] ;

int find(int a) {
    if (a == n[a])
        return a;
    int p = find(n[a]);
    len[a] = len[p];
    n[a] = p;
    return p;
}

int unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        n[a] = b;
        len[a] = len[b] = len[a] + len[b];
    }
    return len[a];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 1; i < 200005; ++i) {
            n[i] = i;
            len[i] = 1;
        }
        map<string, int> m;
        vector<pair<int, int>> fr(N);
        int idx = 0;
        char inputa[21], inputb[21];
        for (int i = 0; i < N; ++i) {
            scanf("%s %s", inputa, inputb);
            string a = inputa, b = inputb;
            if (m[a] == 0) 
                m[a] = ++idx;
            if (m[b] == 0)
                m[b] = ++idx;
            fr[i] = { m[a], m[b] };
        }

        for (int i = 0; i < N; ++i) {
            int ans = unionSet(fr[i].first, fr[i].second);
            printf("%d\n", ans);
        }
    }


    return 0;
}