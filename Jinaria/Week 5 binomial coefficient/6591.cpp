#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    int temp = n;
    for (int i = n - 1; i > 0; i--) {
        temp *= i;
    }
    return temp;
}

int main() {
    int N, K;
    cin >> N >> K;

    int result = factorial(N) / (factorial(K) * factorial(N - K));
    cout << result << '\n';
}