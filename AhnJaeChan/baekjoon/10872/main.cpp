#include <iostream>

using namespace std;

uint solve(uint N) {
    uint twos = 0;
    uint fives = 0;

    for (uint i = 2; i <= N; ++i) {
        uint tmp = i;

        while (!(tmp & 0x1u)) {
            tmp >>= 1u;
            twos++;
        }

        tmp = i;
        while (tmp % 5 == 0) {
            tmp /= 5;
            fives++;
        }
    }

    return twos < fives ? twos : fives;
}

int main() {
    uint N;

    cin >> N;
    cout << solve(N) << endl;

    return 0;
}