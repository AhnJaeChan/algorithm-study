#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M       1000000

int d[5001];

int main() {
    string num;
    cin >> num;

    if (num[0] == '0') {
        printf("0\n");
        return 0;
    }

    int ans = 0;

    d[0] = d[1] = 1;
    for (int i = 2; i <= num.size(); ++i) {
        int now = i - 1;
        if (num[now] > '0')
            d[i] = d[i - 1];
        int cur_num = (num[now - 1] - '0') * 10 + (num[now] - '0');
        if (cur_num >= 10 && cur_num <= 26)
            d[i] = (d[i] + d[i - 2]) % M;
    }
    ans = d[num.size()];
    printf("%d\n", ans);
    
}