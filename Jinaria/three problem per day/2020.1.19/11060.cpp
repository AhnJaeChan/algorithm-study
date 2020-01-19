#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int d[1001];

int main() {
    int N;
    scanf("%d", &N);
    vector<int> miro(N + 1);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &miro[i]);
    
    for (int i = 1; i <= N; ++i)
        d[i] = 1234567890;
    d[1] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= i + miro[i]; ++j) {
            if (j > N)
                break;
            d[j] = min(d[j], d[i] + 1);
        }
    }
    if (d[N] == 1234567890)
        printf("-1\n");
    else
        printf("%d\n", d[N]);
}