#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int N, R;
int pill[101];
int react[101][101];

int main() {
    for (int i = 0; i <= 100; ++i) {
        pill[i] = -1;
    }
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int n, e;
        scanf("%d %d", &e, &n);
        pill[e] = n;
    }
    scanf("%d", &R);
    for (int i = 0; i < R; ++i) {
        scanf("%d", &react[i][0]);
        for (int j = 1; j <= react[i][0]; ++j) {
            scanf("%d", &react[i][j]);
        }
    }
    for (int i = 0; i < R; ++i) {
        vector<int> ans;
        for (int j = 1; j <= react[i][0]; ++j) {
            if (pill[react[i][j]] >= 0) {
                ans.push_back(pill[react[i][j]]);
            }
            else {
                ans.clear();
                break;
            }
        }
        if (ans.size()) {
            for (auto it = ans.begin(); it != ans.end(); ++it){
                printf("%d ", *it);
            }
            printf("\n");
        }
        else {
            printf("YOU DIED\n");
        }
    }



    return 0;
}