#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int NUM_CLOCK = 16;

vector<vector<int> > clock_switch = { {0, 1, 2},
									   {3, 7, 9, 11},
									   {4, 10, 14, 15},
									   {0, 4, 5, 6, 7},
									   {6, 7, 8, 10, 12},
									   {0, 2, 14, 15},
									   {3, 14, 15},
									   {4, 5, 7, 14, 15},
									   {1, 2, 3, 4, 5},
									   {3, 4, 5, 9, 13} };

void check() {

}

int main() {
	int C;
	cin >> C;
	while (C--) {
		vector<int> clock_state(NUM_CLOCK);
		for (int i = 0; i < NUM_CLOCK; i++) cin >> clock_state[i];

	}
}