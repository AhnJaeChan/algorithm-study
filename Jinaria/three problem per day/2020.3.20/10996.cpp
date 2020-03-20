#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= (n - 1) / 2; ++j) {
            cout << "* ";
        }
        cout << '\n';
        for (int j = 0; j < n / 2; ++j) {
            cout << " *";
        }
        cout << '\n';
    }
}