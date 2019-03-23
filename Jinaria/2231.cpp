#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int INF = 100000000;

int ret = INF;

void check(int cipher, vector<int> &num, int origin_num) {
	if (cipher == 0) {
		for (int i = 0; i < num.size(); i++) {
			int temp = origin_num % (int)pow(10.0, i + 1) / pow(10.0, i);
			if (num[i] != temp) {
				return;
			}
		}
		ret = min(ret, origin_num);
		return;
	}
	else {
		for (int i = 0; i <= 9; i++) {
			num.push_back(i);
			check(cipher - 1, num, origin_num - i);
			num.pop_back();
		}
	}
}

int main() {
	int N;
	cin >> N;
	int cipher = 1, temp = N;
	while (temp /= 10) {
		cipher++;
	}
	vector<int> num;
	check(cipher, num, N);
	if (ret == INF) cout << 0 << endl;
	else cout << ret << endl;
}