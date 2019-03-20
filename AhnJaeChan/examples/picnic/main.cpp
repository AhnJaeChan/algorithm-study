#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int countPairs(bool areFriends[10][10], int N, bool isSelected[10]);

int main(int argc, char **argv) {
    string input_file_name("input.txt");
    ifstream input_stream(input_file_name);
    if (!input_stream.is_open()) {
        return -1;
    }

    string output_file_name("output.txt");
    ofstream output_stream(output_file_name);
    if (!output_stream.is_open()) {
        return -2;
    }

    int C;
    input_stream >> C;

    for (int i = 0; i < C; i++) {
        int N, M;
        input_stream >> N >> M;

        bool areFriends[10][10];
        bool isSelected[10];

        for (int k = 0; k < N; k++) {
            for (int l = 0; l < N; l++) {
                areFriends[k][l] = false;
            }

            isSelected[k] = false;
        }

        for (int j = 0; j < M; j++) {
            int x, y;
            input_stream >> x >> y;

            areFriends[x][y] = true;
            areFriends[y][x] = true;
        }

        output_stream << countPairs(areFriends, N, isSelected) << endl;
    }

    if (input_stream.is_open()) {
        input_stream.close();
    }

    if (output_stream.is_open()) {
        output_stream.close();
    }

    return 0;
}

int countPairs(bool areFriends[10][10], int N, bool isSelected[10]) {
    int nearestUnselected = -1;
    int i;

    for (i = 0; i < N; i++) {
        if (!isSelected[i]) {
            nearestUnselected = i;
            break;
        }
    }

    if (nearestUnselected == -1) {
        return 1;
    }

    int cnt = 0;
    for (i = nearestUnselected + 1; i < N; i++) {
        if (isSelected[i] || !areFriends[nearestUnselected][i]) continue;
        isSelected[i] = isSelected[nearestUnselected] = true;
        cnt += countPairs(areFriends, N, isSelected);
        isSelected[i] = isSelected[nearestUnselected] = false;
    }

    return cnt;
}
