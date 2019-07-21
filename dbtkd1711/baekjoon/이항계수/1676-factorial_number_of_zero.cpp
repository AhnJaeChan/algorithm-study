#include <iostream>

using namespace std;

int N;
int number_of_zero(int n);
int count2(int n);
int count5(int n);

int main() {
    cin >> N;
    cout << number_of_zero(N) << endl;
    return 0;
}

int number_of_zero(int n) {
    if(n == 0)
        return 0;

    int count = 0;
    int number_of_2 = 0;
    int number_of_5 = 0;
    for(int i = 1 ; i <= n ; i++) {
        number_of_2 += count2(i);
        number_of_5 += count5(i);
    }
    if(number_of_2 > number_of_5)
        return number_of_5;
    else
        return number_of_2;
}
int count2(int n) {
    int temp = n;
    int count = 0;
    while(1) {
        if(temp%2 == 0) {
            count++;
            temp /= 2;
        }
        else
            break;
    }
    return count;
}
int count5(int n) {
    int temp = n;
    int count = 0;
    while(1) {
        if(temp%5 == 0) {
            count++;
            temp /= 5;
        }
        else
            break;
    }
    return count;
}