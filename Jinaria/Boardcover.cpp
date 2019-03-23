#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int C, H, W, _count;



int block[4][3][2] = { {{0, 0}, {0, 1}, {1, 1}},
					{{0, 0}, {1, 0}, {1, -1}},
					{{0, 0}, {1, 0}, {1, 1}},
					{{0, 0}, {0, 1}, {1, 0}} };

bool put_block(int start, int shape, vector<vector<bool> > &board, bool put) {
	int y = start / W, x = start % W;
	if (put) {
		if (y == H - 1) { if (block[shape][1][0] == 1 || block[shape][2][0] == 1) { return false; } }
		if (x == W - 1) { if (block[shape][1][1] == 1 || block[shape][2][1] == 1) { return false; } }
		if (x == 0) { if (block[shape][1][1] == -1 || block[shape][2][1] == -1) { return false; } }
		if (!board[y + block[shape][1][0]][x + block[shape][1][1]] && !board[y + block[shape][2][0]][x + block[shape][2][1]]) {
			board[y + block[shape][0][0]][x + block[shape][0][1]] = board[y + block[shape][1][0]][x + block[shape][1][1]] = board[y + block[shape][2][0]][x + block[shape][2][1]] = true;
			return true;
		}
		else return false;
	}
	else {
		board[y + block[shape][0][0]][x + block[shape][0][1]] = board[y + block[shape][1][0]][x + block[shape][1][1]] = board[y + block[shape][2][0]][x + block[shape][2][1]] = false;
		return true;
	}
	
}

void check(int block_num, vector<vector<bool> > board) {
	int start;
	for (start = 0; start < H * W; start++) {
		if (!board[start / W][start % W]) break;
	}

	if (start >= H * W) { _count++; return; }

	for (int i = 0; i < 4; i++) {
		if (put_block(start, i, board, true)) {
			check(block_num + 1, board);
			put_block(start, i, board, false);
		}
	}
}

int main() {
	cin >> C;
	while (C--) {
		cin >> H >> W;
		vector<vector<bool> > board(H, vector<bool>(W, false));
		char c;
		int black = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> c;
				if (c == '#') { board[i][j] = true;  black++; }
			}
		}
		int white = H * W - black;
		if (white % 3 == 0) check(0, board);
		cout << _count << endl;
		_count = 0;
	}

	}