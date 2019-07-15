class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int column[10];
        int row[10];
        int box[10];
        bool flag = true;
        for (int i = 0; i < 9; i++) {
            fill_n(column, 10, 0);
            fill_n(row, 10, 0);
            fill_n(box, 10, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int c = board[i][j] - '0';
                    if (column[c] == 1) return false;
                    else column[c] = 1;
                }
                if (board[j][i] != '.') {
                    int r = board[j][i] - '0';
                    if (row[r] == 1) return false;
                    else row[r] = 1;
                }
                if (board[j / 3 + i / 3 * 3][j % 3 + i % 3 * 3] != '.') {
                    int b = board[j / 3 + i / 3 * 3][j % 3 + i % 3 * 3] - '0';
                    if (box[b] == 1) return false;
                    else box[b] = 1;
                }
            }
        }
        return true;
    }
};