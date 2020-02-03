#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N, M;
    scanf("%d", &N);
    vector<int> card(N);
    int t;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &t);
        card[i] = t;
    }
    sort(card.begin(), card.end());
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d", &t);
        int k = upper_bound(card.begin(), card.end(), t) - lower_bound(card.begin(), card.end(), t);
        printf("%d ", k);
    }
    printf("\n");

}