#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

const int BLACK = 0;
const int WHITE = 1;

string reverse(string::iterator &iter) {
    char front = *iter++;

    if (front != 'x') {
        return front == 'b' ? "b" : "w";
    }

    string up_left = reverse(iter);
    string up_right = reverse(iter);
    string down_left = reverse(iter);
    string down_right = reverse(iter);

    return "x" + down_left + down_right + up_left + up_right;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;

        string::iterator iter = S.begin();
        string ret = reverse(iter);

        cout << ret << endl;

    }

}