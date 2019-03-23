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
    // every cipher has range 0 ~ 9, so difference between origin_num and N is digit multiplied by 10 at most.
    int sub_origin_num = cipher * 10; 
    int origin_num = 0;
    for (int i = N - sub_origin_num; i < N; i++) {
        int sum = i;
        for (int j = 0; j < cipher; i++) {
            sum += i / pow(10, j) % 10;
        }
        // We want the mininmum number, so we stop as soon as we find the matching value.
        if (sum == N) {
            origin_num = i;
            break;
        }

    }
}