#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define GRAPH(T) vector<vector<T>>

int dfs(GRAPH(int) &house, GRAPH(int) &check, int i, int j, int num) {
    if (i < 0 || i >= house.size()) return 0;
    if (j < 0 || j >= house[0].size()) return 0;
    if (house[i][j] == 0)
        return 0;
    if (check[i][j])
        return 0;
    check[i][j] = num;
    int ret = 1;
    ret += (dfs(house, check, i - 1, j, num) + dfs(house, check, i + 1, j, num) + dfs(house, check, i, j - 1, num) + dfs(house, check, i, j + 1, num));
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);
    GRAPH(int) house(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            while ((house[i][j] = getchar()) == '\n');
            house[i][j] -= '0';
        }
    }
        
    GRAPH(int) check(N, vector<int>(N, 0));
    int result = 0;
    vector<int> estate;
    int num = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int t = dfs(house, check, i, j, num);
            if (t > 0) {
                estate.push_back(t);
                num++;
            }
        }
    }
    sort(estate.begin(), estate.end());
    printf("%d\n", num - 1);
    for (auto a : estate)
        printf("%d\n", a);
}