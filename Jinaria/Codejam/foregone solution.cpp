#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        string N;
        cin >> N;
        string::iterator iter = N.end();
        int B = 0;
        for (int i = 0; iter != N.begin() - 1; i++) {
            iter--;
            if (*iter == '4') {
                *iter = '3';
                B += pow(10, i);
            }

        }
        cout << "Case #" << test + 1 << ": " << N << " " << B << endl;
    }


}