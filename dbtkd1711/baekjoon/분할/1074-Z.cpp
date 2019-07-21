#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;

int when_visited(int row, int column, int length);

int main() {
    cin >> N >> r >> c;

    int answer = when_visited(r, c, N);

    cout << answer << endl;
    return 0;
}

int when_visited(int row, int column, int length) {
    if(length == 1) {
        int count = 0;

        return row*2 + column;
    }

    int index = pow(2, length - 1);

    if(row < index && column < index)
        return when_visited(row, column, length - 1);

    else if(row < index && column >= index)
        return index*index + when_visited(row, column - index, length - 1);

    else if(row >= index && column < index)
        return 2*index*index + when_visited(row - index, column, length - 1);

    else if(row >= index && column >= index)
        return 3*index*index + when_visited(row - index, column - index, length - 1);

    return 0;
}
