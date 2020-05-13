#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int N, K;
string nums[16];
char input[51];
int d[1 << 16][100];

int getRemain(string& num) {
    int ret = 0;
    for (int i = 0; i < num.size(); ++i) {
        ret = ret * 10 + (num[i] - '0');
        ret %= K;
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", input);
        nums[i] = input;
    }
    scanf("%d", &K);

    for (int i = 1; i <= N; ++i) {
        
    }




    return 0;
}