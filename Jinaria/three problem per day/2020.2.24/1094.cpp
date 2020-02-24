#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int K;
    scanf("%d", &K);
    
    int num = 64;
    int ans = 0;
    while (K >= 1) {
        if (K >= num) {
            K -= num;
            ans++;
        }
        else {
            num /= 2;
        }
    }
    printf("%d\n", ans);
}