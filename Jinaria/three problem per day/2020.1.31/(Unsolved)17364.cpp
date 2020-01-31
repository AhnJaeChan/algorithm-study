#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <set>

using namespace std;

#define MAX_NUM     1000000007

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<pair<int, int>> contest(N);
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &contest[i].second, &contest[i].first);

    sort(contest.begin(), contest.end());
    
    set<pair<int, int>> end_set;
    vector<int> store(N + 1);
    int ans = 0;
    int ke = 0;
    int cur_k = 0;
    for (int i = 0; i < N; ++i) {
        int cur_start = contest[i].second, cur_end = contest[i].first;

        if (ke >= cur_start)
            continue;
        bool flag = false;
        if (end_set.size() < K - 1) {
            end_set.insert({ MAX_NUM - cur_end, ++cur_k });
            store[cur_k] = MAX_NUM - cur_end;
            flag = true;
        }
        else {
            auto k = end_set.lower_bound({ MAX_NUM - cur_start, 0 });
            if (k != end_set.end()) {
                if (store[k->second] == MAX_NUM - cur_start)
                    k++;
                if (k != end_set.end()) {
                    int ck = k->second;
                    end_set.erase(k);
                    end_set.insert({ MAX_NUM - cur_end, ck });
                    store[ck] = MAX_NUM - cur_end;
                    flag = true;
                }
                
            }
        }
        if (!flag) {
            ans++;
            ke = cur_end;
        }
    }
    printf("%d\n", ans);
}