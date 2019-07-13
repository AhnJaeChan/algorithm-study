#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int ret = 0;

void move_block(vector<vector<int> > &board, int direction) {
	if (direction == UP) {
		for (int x = 0; x < board.size(); x++) {
			vector<bool> joined(board.size(), false);
			for (int y = 1; y < board.size(); y++) {
			
				if (board[y][x] == 0) continue;
				
				for (int i = y - 1; i >= 0; i--) {
					if (board[i][x] == 0) {
						board[i][x] = board[i + 1][x];
						board[i + 1][x] = 0;
					}
					else if (board[i][x] == board[i + 1][x] && !joined[i] && !joined[i + 1]) {
						board[i][x] += board[i + 1][x];	
						board[i + 1][x] = 0;
						joined[i] = true;
					}
					else break;
				}
				
			}
		}
	}
	else if (direction == RIGHT) {

		for (int y = 0; y < board.size(); y++) {
			vector<bool> joined(board.size(), false);
			for (int x = board.size() - 2; x >= 0; x--) {
			
				if (board[y][x] == 0) continue;
				
				for (int i = x + 1; i < board.size(); i++) {
					if (board[y][i] == 0) {
						board[y][i] = board[y][i - 1];
						board[y][i - 1] = 0;
					}
					else if (board[y][i] == board[y][i - 1] && !joined[i] && !joined[i - 1]) {
						board[y][i] += board[y][i - 1];
						board[y][i - 1] = 0;
						joined[i] = true;
					}
					else break;
				}
				
			}
		}
	}
	else if (direction == DOWN) {
		for (int x = 0; x < board.size(); x++) {
			vector<bool> joined(board.size(), false);
			for (int y = board.size() - 2; y >= 0; y--) {
			
				if (board[y][x] == 0) continue;
				
				for (int i = y + 1; i < board.size(); i++) {
					if (board[i][x] == 0) {
						board[i][x] = board[i - 1][x];
						board[i - 1][x] = 0;
					}
					else if (board[i][x] == board[i - 1][x] && !joined[i] && !joined[i - 1]) {
						board[i][x] += board[i - 1][x];
						board[i - 1][x] = 0;
						joined[i] = true;
					}
					else break;
				}
				
			}
		}
	}
	else if (direction == LEFT) {
		for (int y = 0; y < board.size(); y++) {
			vector<bool> joined(board.size(), false);
			for (int x = 1; x < board.size(); x++) {	
			
				if (board[y][x] == 0) continue;
				
				for (int i = x - 1; i >= 0; i--) {
					if (board[y][i] == 0) {
						board[y][i] = board[y][i + 1];
						board[y][i + 1] = 0;
					}
					else if (board[y][i] == board[y][i + 1] && !joined[i] && !joined[i + 1]) {
						board[y][i] += board[y][i + 1];
						board[y][i + 1] = 0;
						joined[i] = true;
					}
					else break;
				}

			}
		}
	}
}

void check(vector<vector<int> > board, int cnt) {
	if (cnt == 0) {
		for (auto a : board) {
			for (auto b : a) {
				ret = max(ret, b);
			}
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			auto temp = board;
			move_block(temp, i);
			check(temp, cnt - 1);
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<vector<int> > board(N, vector<int>(N));

	for (auto &a : board) {
		for (auto &b : a) {
			cin >> b;
		}
	}

	check(board, 5);

	cout << ret << endl;
	
}