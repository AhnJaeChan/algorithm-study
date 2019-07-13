/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

long long int Answer;

void move(int *x, int *y, char move) {
  switch (move) {
    case 'U':
      (*x)--;
      break;
    case 'D':
      (*x)++;
      break;
    case 'L':
      (*y)--;
      break;
    case 'R':
      (*y)++;
      break;
    default:
      return;
  }
}

int sigma(int x) {
  return x * (x + 1) / 2;
}

int main(int argc, char **argv) {
  int T, test_case;
  int N, K, sqr;
  char c;
  int row, col;
  int x, y, z;

  /*
     The freopen function below opens input.txt file in read only mode, and afterward,
     the program will read from input.txt file instead of standard(keyboard) input.
     To test your program, you may save input data in input.txt file,
     and use freopen function to read from the file when using cin function.
     You may remove the comment symbols(//) in the below statement and use it.
     Use #include<cstdio> or #include <stdio.h> to use the function in your program.
     But before submission, you must remove the freopen function or rewrite comment symbols(//).
   */

  cin >> T;
  for (test_case = 0; test_case < T; test_case++) {

    Answer = 1;
    /////////////////////////////////////////////////////////////////////////////////////////////
    /*
       Implement your algorithm here.
       The answer to the case will be stored in variable Answer.
     */
    row = col = 0;

    cin >> N >> K;

    sqr = N * N;

    for (int i = 0; i < K; ++i) {
      cin >> c;

      move(&row, &col, c);

      if (row + col < N) {
        x = row;
        y = col;

        z = x + y;
        if (z % 2) { // odd, left down
          Answer = Answer + sigma(z) + 1 + x;
        } else { // even, right up
          Answer = Answer + sigma(z) + 1 + y;
        }
      } else {
        x = (N - 1) - row;
        y = (N - 1) - col;

        z = x + y;
        if (z % 2) { // odd, left down
          Answer = Answer + sqr + 1 - (sigma(z) + 1 + x);
        } else { // even, right up
          Answer = Answer + sqr + 1 - (sigma(z) + 1 + y);
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