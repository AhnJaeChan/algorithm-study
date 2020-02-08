#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_RANGE     1000000001


int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    vector<int> house(N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &house[i]);

    sort(house.begin(), house.end());

    int start = 1, end = *house.rbegin();
    int ans = 0;
    while (start <= end) {
        int mid = (start + end) / 2;
        int cur_point = *house.begin();
        vector<int>::iterator next;
        for (int i = 1; i < C; ++i) {
            next = lower_bound(house.begin(), house.end(), cur_point + mid);
            if (next == house.end()) {
                end = mid - 1;
                break;
            }
            cur_point = *next;
        }
        if (next == house.end()) {
            continue;
        }
        ans = mid;
        start = mid + 1;
    }


    printf("%d\n", ans);

}