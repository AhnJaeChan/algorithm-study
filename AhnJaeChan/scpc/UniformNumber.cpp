/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <cmath>

using namespace std;

int Answer;

int findBase(int N) {
  int b;

  for (b = 2; b < (int) sqrt(N); ++b) {
    int k = 2;
    while (pow(b, ++k) < N);

    int sigma = ((int) pow(b, k) - 1) / (b - 1);

    if (N % sigma == 0 && N / sigma < b) {
      return b;
    }
  }

  for (int a = (int) sqrt(N) + 1; a >= 1; --a) {
    if (N % a == 0 && (N / a - 1) > a) {
      return (N / a - 1);
    }
  }

  return N + 1;
}

int main(int argc, char **argv) {
  int T, test_case;
  int N;
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

    Answer = findBase(N);

    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0;//Your program should return 0 on normal termination.
}