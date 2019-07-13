/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int N;
int contestant[300000];

int solve(int left, int right) {
  int mid = (right + left) / 2;

  if (left > right) {
    return left;
  }

  int score = contestant[mid] + mid;

  if (score >= *max_element(contestant + mid + 1, contestant + N)) {
    return solve(left, mid - 1);
  } else {
    return solve(mid + 1, right);
  }
}

int main(int argc, char **argv) {
  int T, test_case;

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
      cin >> contestant[i];
    }

    sort(contestant, contestant + N);

    for (int i = 0; i < N; ++i) {
      contestant[i] += (N - i);
    }

    Answer = N - solve(0, N - 1);
    /////////////////////////////////////////////////////////////////////////////////////////////

    // Print the answer to standard output(screen).
    cout << "Case #" << test_case + 1 << endl;
    cout << Answer << endl;
  }

  return 0;//Your program should return 0 on normal termination.
}