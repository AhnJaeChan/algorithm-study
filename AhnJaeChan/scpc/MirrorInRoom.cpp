/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <utility>
#include <string>

using namespace std;

int Answer;
pair<int, bool> mirror[1000][1000];

int main(int argc, char **argv) {
  int T, test_case;
  int N;
  string input;
  /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using cin function.
     You may remove the comment symbols(//) in the below statement and use it.
     Use #include<cstdio> or #include <stdio.h> to use the function in your program.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
   */

  // freopen("input.txt", "r", stdin);

  cin >> T;
  for (test_case = 0; test_case < T; test_case++) {

    Answer = 0;
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*
       Implement your algorithm here.
       The answer to the case will be stored in variable Answer.
     */
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> input;

      for (int j = 0; j < N; ++j) {
        mirror[i][j].first = input[j] - '0';
        mirror[i][j].second = false;
      }
    }

    int row, col;
    row = col = 0;

    int light = 0; // 0: right, 1: left, 2: down, 3: up (ex. 0 means light's direction is left to right)

    while (row >= 0 && row < N && col >= 0 && col < N) {
      if (mirror[row][col].first == 0) { // None
        // light stays,
        if (light == 0) {
          col++;
        } else if (light == 1) {
          col--;
        } else if (light == 2) {
          row++;
        } else {
          row--;
        }
      } else if (mirror[row][col].first == 1) {
        if (!mirror[row][col].second) {
          Answer++;
          mirror[row][col].second = true;
        }
        if (light == 0) {
          row--;
          light = 3;
        } else if (light == 1) {
          row++;
          light = 2;
        } else if (light == 2) {
          col--;
          light = 1;
        } else {
          col++;
          light = 0;
        }
      } else {
        if (!mirror[row][col].second) {
          Answer++;
          mirror[row][col].second = true;
        }
        if (light == 0) {
          row++;
          light = 2;
        } else if (light == 1) {
          row--;
          light = 3;
        } else if (light == 2) {
          col++;
          light = 0;
        } else {
          col--;
          light = 1;
        }
      }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0;//Your program should return 0 on normal termination.
}