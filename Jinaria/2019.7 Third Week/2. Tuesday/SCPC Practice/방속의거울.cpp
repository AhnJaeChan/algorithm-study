#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int MAX_ROOM = 1000;

int Answer;
int N;
string room[MAX_ROOM];
int reflect[MAX_ROOM][MAX_ROOM];


int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> room[i];
        int i = 0, j = 0;
        bool flag = false;
        int lightdir = 6;
        while (!flag) {
            switch (lightdir) {
            case 6: // right
                if (room[i][j] == '0') j++; // no mirror
                else if (room[i][j] == '1') { reflect[i][j] = test_case + 1; i--; lightdir = 8; } // left down mirror
                else if (room[i][j] == '2') { reflect[i][j] = test_case + 1; i++; lightdir = 2; } // right down mirror
                break;
            case 2: // down
                if (room[i][j] == '0') i++; // no mirror
                else if (room[i][j] == '1') { reflect[i][j] = test_case + 1; j--; lightdir = 4; } // left down mirror
                else if (room[i][j] == '2') { reflect[i][j] = test_case + 1; j++; lightdir = 6; } // right down mirror
                break;
            case 4: // left
                if (room[i][j] == '0') j--; // no mirror
                else if (room[i][j] == '1') { reflect[i][j] = test_case + 1; i++; lightdir = 2; } // left down mirror
                else if (room[i][j] == '2') { reflect[i][j] = test_case + 1; i--; lightdir = 8; } // right down mirror
                break;
            case 8: // up
                if (room[i][j] == '0') i--; // no mirror
                else if (room[i][j] == '1') { reflect[i][j] = test_case + 1; j++; lightdir = 6; } // left down mirror
                else if (room[i][j] == '2') { reflect[i][j] = test_case + 1; j--; lightdir = 4; } // right down mirror
                break;
            }
            if (i < 0 || i > N - 1 || j < 0 || j > N - 1) flag = true;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (reflect[i][j] == test_case + 1) Answer++;
            }
        }



        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}