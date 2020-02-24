#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int N, M;
    scanf("%d %d", &M, &N);

    vector<int> ans;
    for (int i = M; i <= N; ++i) {
        int c = (int)sqrt(i);
        if (c * c == i) {
            ans.push_back(i);
        }
    }
    int sum = 0;
    for (int a : ans) {
        sum += a;
    }
    if (ans.size() == 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n%d\n", sum, ans[0]);
    }
}