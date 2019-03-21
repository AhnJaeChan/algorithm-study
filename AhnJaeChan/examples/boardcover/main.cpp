#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ROTATION_COORDS[4][2][2] = {{{1, 0}, {0,  1}},
                                      {{1, 0}, {1,  1}},
                                      {{0, 1}, {1,  1}},
                                      {{0, 1}, {-1, 1}}};

int countCases(bool board[20][20], int H, int W);

bool isBoundValid(int y, int x, int H, int W);

int main() {
    string input_file_name("input.txt");
    ifstream input_stream(input_file_name);

    if (!input_stream.is_open()) {
        return -1;
    }

    string output_file_name("output.txt");
    ofstream output_stream(output_file_name);

    if (!output_stream.is_open()) {
        return -1;
    }

    int C;
    int W, H;

    input_stream >> C;

    for (int i = 0; i < C; i++) {
        input_stream >> H >> W;

        bool board[20][20];
        char color;
        int black_cnt = 0;

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                input_stream >> color;

                if (color == '#') {
                    board[h][w] = true;
                    black_cnt++;
                } else {
                    board[h][w] = false;
                }
            }
        }

        if ((W * H - black_cnt) % 3 != 0) {
            output_stream << 0 << endl;
            continue;
        }

        output_stream << countCases(board, H, W) << endl;
    }

    if (input_stream.is_open()) {
        input_stream.close();
    }

    if (output_stream.is_open()) {
        output_stream.close();
    }

    return 0;
}

int countCases(bool board[20][20], int H, int W) {
    int w = -1, h = -1;
    int i, j;

    for (i = 0; i < H; i++) {
        for (j = 0; j < W; j++) {
            if (!board[i][j]) {
                h = i;
                w = j;
                break;
            }
        }
        if (w != -1) break;
    }

    if (w == -1) return 1; // Case all filled.

    int cnt = 0;
    for (i = 0; i < 4; i++) {
        int x1 = w + ROTATION_COORDS[i][0][0];
        int y1 = h + ROTATION_COORDS[i][0][1];

        int x2 = w + ROTATION_COORDS[i][1][0];
        int y2 = h + ROTATION_COORDS[i][1][1];

        if (!isBoundValid(y1, x1, H, W)) continue; // out of bounds
        if (!isBoundValid(y2, x2, H, W)) continue; // out of bounds

        if (board[y1][x1] || board[y2][x2]) continue; // already filled

        board[h][w] = board[y1][x1] = board[y2][x2] = true;
        cnt += countCases(board, H, W);
        board[h][w] = board[y1][x1] = board[y2][x2] = false;
    }
    return cnt;
}

bool isBoundValid(int y, int x, int H, int W) {
    return !(y < 0 || y >= H || x < 0 || x >= W);
}