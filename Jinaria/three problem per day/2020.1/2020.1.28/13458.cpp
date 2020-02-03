#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, B, C;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    long long ans = 0;
    for (int num : A) {
        if (num <= B)
            ans += 1;
        else {
            long long a;
            a = (num - B) / C + 1 + ((num - B) % C != 0);

            if ((num - B) % C == 0)
                a = (num - B) / C + 1;
            else
                a = (num - B) / C + 2;
            ans += a;
        }
    }
    printf("%lld\n", ans);
}