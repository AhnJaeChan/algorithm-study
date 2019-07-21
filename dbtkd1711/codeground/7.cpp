/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

int Answer;
int main(int argc, char** argv)
{
	int T, test_case, N, input, i, j, k;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int two[400001] = {0, };
        int numbers[5000] = {0, };

        cin >> N;
        for(i = 0 ; i < N ; i++) {
            cin >> input;
            numbers[i] = input;
        }

		Answer = 0;
        for(i = 0 ; i < N ; i++) {
            for(j = 0 ; j < i ; j++) {
                if(two[numbers[i] - numbers[j] + 200000] == 1) {
                    Answer++;
                    break;
                }
            }
            for(j = 0 ; j <= i ; j++) {
                two[numbers[i] + numbers[j] + 200000] = 1;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
