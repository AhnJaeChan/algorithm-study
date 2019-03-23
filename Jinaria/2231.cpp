#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	int N;
	cin >> N;
	int cipher = 1, temp = N;
	while (temp /= 10) {
		cipher++;
	}
    int sub_origin_num = cipher * 10;
    int origin_num = 0;
    for (int i = N - sub_origin_num; i < N; i++) {
        int sum = i;
        for (int j = 0; j < cipher; i++) {
            sum += i / pow(10, j) % 10;
        }
        if (sum == N) {
            origin_num = i;
            break;
        }

    }
}