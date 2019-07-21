#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
int d[1000000] = {-1, };
int combination(int n, int r);
int find(int front, int index);

int main() {
    cin >> N;

    return 0;
}

int find(int front, int index) {
    for(int i = front - 1 ; i > -1 ; i--) {
        find(i, index - 1);
    }
}

int combination(int n, int r) {
    if(n == r || r == 0)
        return 1;
    return combination(n-1, r-1) + combination(n-1, r);
}
