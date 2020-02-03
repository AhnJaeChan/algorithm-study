#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> port(n + 1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &port[i]);

    vector<int> d;
    for (int i = 1; i <= n; ++i) {
        if (d.empty() || d.back() < port[i])
            d.push_back(port[i]);
        else {
            auto ch = lower_bound(d.begin(), d.end(), port[i]);
            *ch = port[i];
        }
    }
    printf("%d\n", d.size());

}