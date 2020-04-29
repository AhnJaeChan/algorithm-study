#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NUM     123456789

int N;
int nums[100001];
int sub[100001];


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &nums[i]);
    if (N == 2) {
        printf("2\n");
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < N - 1; ++i) {
        sub[i] = nums[i + 1] - nums[i];
        if (sub[i] < 0)
            count++;
    }
    if (count == 0) {
        printf("%d\n", N);
    }
    else if (count == 1) {
        int ans = 0;
        for (int i = 0; i < N - 1; ++i) {
            if (sub[i] < 0) {
                if (i == 0) {
                    ans++;
                    if (nums[i + 2] - nums[i] >= 0)
                        ans++;
                    break;
                }
                else if(i == N - 2) {
                    ans++;
                    if (nums[i + 1] - nums[i - 1] >= 0) 
                        ans++;
                    break;
                }
                else {
                    if (nums[i + 2] - nums[i] >= 0)
                        ans++;
                    if (nums[i + 1] - nums[i - 1] >= 0) 
                        ans++;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    else {
        printf("0\n");
    }

    


    return 0;
}