#include <iostream>

using namespace std;

int N;
int factorial(int n);

int main() {
    cin >> N;
    cout << factorial(N) << endl;
    return 0;
}

int factorial(int n) {
    if(n == 0)
        return 1;
    return n*factorial(n-1);
}