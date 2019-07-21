#include <iostream>

using namespace std;

int N, K;

int combination(int n, int r);

int main() {
    cin >> N >> K;
    int answer = combination(N, K);
    cout << answer << endl;
    return 0;
}

int combination(int n, int r) {
    if(n==r or r==0)
        return 1;
    if(r==1)
        return n;
    return combination(n-1, r-1) + combination(n-1, r);
    
}