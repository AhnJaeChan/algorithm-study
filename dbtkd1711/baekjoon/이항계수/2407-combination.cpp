#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

int N, K;
string cache[1001][1001];

void combination(int n, int r);

int main() {
    string a = "2309";
    char b = '2';
    int c = a[0] - '0';
    cout << c << endl;

    cin >> N >> K;
    combination(N, K);
    cout << cache[N][K] << endl;
    return 0;
}

string mult_with_string(string a, string b) {
    int temp1, temp2;
    int mul;
    int carry;
    for(int i = a.length() - 1 ; i >= 0 ; i--) {
        for(int j = b.length() - 1 ; j>=0 ; j--) {
            temp1 = a[i] - '0';
            temp2 = b[j] - '0';
            mul = temp1 * temp2;
        }
    }
}
void combination(int n, int r) {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 0 ; j <= i ; j++) {
            if(i==j || j==0){
                cache[i][j] = 1;
                continue;
            }
            cache[i][j] = cache[i-1][j-1] + cache[i-1][j]; 
        }
    }
    return;
}