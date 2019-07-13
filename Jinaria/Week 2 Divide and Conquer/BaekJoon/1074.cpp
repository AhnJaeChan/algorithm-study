#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int func(int board_size, pair<int, int> point) {
    if (board_size == 2) {
        return point.first * 2 + point.second;
    }
    int index = 0;
    int new_board_size = board_size / 2;
    if (point.first >= new_board_size)
        index += 2;
    if (point.second >= new_board_size)
        index += 1;
    pair<int, int> new_point;
    new_point.first = point.first - (index / 2) * new_board_size;
    new_point.second = point.second - (index % 2) * new_board_size;

    return func(new_board_size, new_point) + index * new_board_size * new_board_size;
}

int main() {
    int N;
    pair<int, int> point;
    cin >> N >> point.first >> point.second;

    int board_size = pow(2, N);

    int ret = func(board_size, point);
    cout << ret << endl;

}