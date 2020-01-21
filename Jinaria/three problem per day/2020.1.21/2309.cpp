#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    vector<int> dwarf(9);
    for (int i = 0; i < 9; ++i)
        scanf("%d", &dwarf[i]);

    int sum = 0;
    for (int tall : dwarf)
        sum = sum + tall;
    int oneminus[9];
    for (int i = 0; i < 9; ++i)
        oneminus[i] = sum - dwarf[i];
    int no1, no2;
    bool flag = false;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (oneminus[i] - dwarf[j] == 100) {
                no1 = i;
                no2 = j;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    vector<int> ans(7);
    int curmax, prevmax = 1234;
    for (int i = 6; i >= 0; --i) {
        curmax = 0;
        for (int j = 0; j < 9; ++j) {
            if (j == no1 || j == no2)
                continue;
            if (curmax < dwarf[j] && dwarf[j] < prevmax)
                curmax = dwarf[j];
        }
        ans[i] = curmax;
        prevmax = curmax;
    }
    for (int i = 0; i < 7; ++i)
        printf("%d\n", ans[i]);
}