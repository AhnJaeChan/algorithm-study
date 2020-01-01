#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string quadtree(vector<string> &board, int n, int size, int col, int row) {
    if (size == 1) {
        if (board[col][row] == '0')
            return string("0");
        return string("1");
    }
    string arr[4];
    int nextSize = size / 2;
    bool flag = true;
    arr[0] = quadtree(board, n, nextSize, col, row);
    if (arr[0] != "0" && arr[0] != "1") flag = false;
    for (int i = 1; i < 4; ++i) {
        arr[i] = quadtree(board, n, nextSize, col + (i >> 1) * nextSize, row + (i & 1) * nextSize);
        if ((arr[i] != "0" && arr[i] != "1") || arr[i - 1].compare(arr[i])) flag = false;
    }
    if (flag) {
        return arr[0];
    }
    else {
        string ret("(");
        for (int i = 0; i < 4; ++i) {
            ret += arr[i];
        }
        ret += string(")");
        return ret;
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    string result = quadtree(board, n, n, 0, 0);
    cout << result << '\n';
 }