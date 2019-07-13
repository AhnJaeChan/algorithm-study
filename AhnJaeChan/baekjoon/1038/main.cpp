#include <iostream>
#include <string>

using namespace std;

int cache[11][11];

string findNum(int digits, int N) {
    if (digits == 1) {
        return to_string(N);
    }

    int accumulate = 0;

    for (int i = digits; i < 10; ++i) {
        if (accumulate + cache[i][digits] > N) {
            return to_string(i) + findNum(digits - 1, N - accumulate);
        }
        accumulate += cache[i][digits];
    }

    return "";
}

int main() {
    int N;

    cin >> N;

    for (int i = 1; i < 11; ++i) {
        cache[i][0] = 1;
    }
    cache[1][1] = 1;

    for (int i = 2; i < 11; ++i) {
        cache[i][1] = i;
        for (int j = 2; j < i + 1; ++j) {
            if (i == j) {
                cache[i][j] = 1;
                continue;
            }

            cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
        }
    }

    for (int n = 1; n < 11; ++n) {
        for (int k = 1; k < n + 1; ++k) {
            cout << cache[n][k] << " ";
        }
        cout << endl;
    }

    int digit_cnt = 0;
    int accumulate = 0;
    for (digit_cnt = 1; digit_cnt < 11; ++digit_cnt) {
        accumulate += cache[10][digit_cnt];
        if (accumulate > N) {
            accumulate -= cache[10][digit_cnt];
            break;
        }
    }

    N -= accumulate;

    cout << findNum(digit_cnt, N) << endl;

    return 0;
}