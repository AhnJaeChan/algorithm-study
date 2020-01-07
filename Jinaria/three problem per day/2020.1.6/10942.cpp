#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> P;

// d[가운데위치][길이]
int d[2001][2001];

int main() {
    int N;
    scanf("%d", &N);
    vector<int> numbers(N + 1);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &numbers[i]);
    int M;
    scanf("%d", &M);
    vector<P> question(M + 1);
    for (int i = 1; i <= M; ++i)
        scanf("%d %d", &question[i].first, &question[i].second);

    for (int i = 0; i <= N; ++i)
        memset(d[i], -1, N + 1);
    for (int i = 1; i <= N; ++i)
        d[i][1] = 1;
    for (int i = 1; i <= N - 1; ++i)
        if (numbers[i] == numbers[i + 1])
            d[i][2] = 1;
        else
            d[i][2] = 0;


    for (int len = 3; len <= N; ++len) {
        int wing = len / 2;
        if (len & 1) {
            for (int idx = 1 + wing; idx <= N - wing; ++idx) {
                if (d[idx][len - 2]) {
                    if (numbers[idx - wing] == numbers[idx + wing])
                        d[idx][len] = 1;
                    else
                        d[idx][len] = 0;
                }
                else {
                    d[idx][len] = 0;
                }
            }
        }
        else {
            for (int idx = 1 + wing - 1; idx <= N - wing; ++idx) {
                if (d[idx][len - 2]) {
                    if (numbers[idx - wing + 1] == numbers[idx + wing])
                        d[idx][len] = 1;
                    else
                        d[idx][len] = 0;
                }
                else {
                    d[idx][len] = 0;
                }
            }
        }
    }
    auto iter = question.begin();

    for (iter++; iter != question.end(); ++iter) {
        printf("%d\n", d[(iter->first + iter->second) / 2][iter->second - iter->first + 1]);
    }


}