#include <iostream>
#include <vector>

using namespace std;

int C, n, m, input;
vector <int> A, B;

int main() {
    cin >> C;
    for(int i = 0 ; i < C ; i++) {
        cin >> n >> m;
        for(int j = 0 ; j < n ; j++) {
            cin >> input;
            A.push_back(input);
        }
        for(int j = 0 ; j < m ; j++) {
            cin >> input;
            B.push_back(input);
        }
    }
    return 0;
}
