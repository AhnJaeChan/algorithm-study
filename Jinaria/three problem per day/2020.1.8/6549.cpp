#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;


int main() {
    long long n;
    scanf("%lld", &n);
    while (n != 0) {
        vector<long long> height(n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &height[i]);

        stack<long long> s;
        long long maxNum = 0;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && height[i] < height[s.top()]) {
                long long cur_height = height[s.top()];
                s.pop();
                long long width = i;
                if (!s.empty())
                    width = i - s.top() - 1;
                if (maxNum < width * cur_height)
                    maxNum = width * cur_height;
            }
            s.push(i);
            
        }
        while (!s.empty()) {
            long long cur_height = height[s.top()];
            s.pop();
            long long width = n;
            if (!s.empty())
                width = n - s.top() - 1;
            if (width * cur_height > maxNum)
                maxNum = width * cur_height;
        }
        printf("%lld\n", maxNum);

        scanf("%lld", &n);
    }
}