#include <iostream>

using namespace std;

int main() {
    int N, fact = 1, two = 0, five = 0, count = 0;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        int temp = i;
        while (temp % 2 == 0) {
            two++;
            temp /= 2;
        }
        temp = i;
        while (temp % 5 == 0) {
            five++;
            temp /= 5;
        }
    }
    count = two < five ? two : five;
    cout << count << '\n';
}