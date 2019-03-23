#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    vector<int> heights;
    int height;
    int i, j;

    for (i = 0; i < 9; i++) {
        cin >> height;
        heights.push_back(height);
    }

    sort(heights.begin(), heights.end(), less<int>());

    int sum = accumulate(heights.begin(), heights.end(), 0);
    sum -= 100;

    int x = -1, y = -1;
    for (i = 0; i < 8; i++) {
        for (j = i + 1; j < 9; j++) {
            if (heights[i] + heights[j] == sum) {
                x = i;
                y = j;
                break;
            }
        }

        if (x != -1) break;
    }

    for (i = 0; i < 9; i++) {
        if (i == x || i == y) continue;

        cout << heights[i] << endl;
    }

    return 0;
}
