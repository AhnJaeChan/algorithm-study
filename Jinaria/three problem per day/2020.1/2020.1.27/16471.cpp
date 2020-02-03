#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> jueon(N);
    map<int, int> sajang;
    for (int i = 0; i < N; ++i)
        scanf("%d", &jueon[i]);
    for (int i = 0; i < N; ++i) {
        int k;
        scanf("%d", &k);
        sajang[k]++;
    }

    sort(jueon.begin(), jueon.end());

    int score = 0;
    int goal = (N + 1) / 2;

    for (int num : jueon) {
        auto upper = sajang.upper_bound(num);


        if (upper != sajang.end() && upper->second > 0) {
            upper->second--;
            if (upper->second == 0)
                sajang.erase(upper);
            score++;
        }
    }
    
    if (score >= goal)
        printf("YES\n");
    else
        printf("NO\n");

}