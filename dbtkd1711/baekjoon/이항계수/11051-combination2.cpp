#include <iostream>

using namespace std;

int N, K;
int cache[1001][1001];

void combination(int n, int r);

int main() {
    cin >> N >> K;
    combination(N, K);
    cout << cache[N][K] << endl;
    return 0;
}

void combination(int n, int r) {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(i==j || j==0){
                cache[i][j] = 1;
                continue;
            }
            cache[i][j] = (cache[i-1][j-1] + cache[i-1][j])%10007; 
        }
    }
    return;
}