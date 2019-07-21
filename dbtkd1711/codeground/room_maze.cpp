/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;



long long int Answer;
int N;
long long int numbers(int i, int j) {
    int index = i + j;
    long long int sum = 0;
    int k, l;
    if(index < N) {
        sum += index * (index + 1) / 2;
        if(index % 2 == 0)
            sum += j + 1;
        else
            sum += i + 1;
    }
    else {
        sum += N*N;
        sum -= (2*N - index - 1) * (2*N - index) / 2;
        if(index % 2 == 0)
            sum += j - (index - N);
        else
            sum += i - (index - N);
    }
    return sum;
};

int main(int argc, char** argv)
{
	int T, test_case, K;
    char input;
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
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N >> K;
		Answer = 0;
        int i = 0, j = 0;
        for(int k = 0 ; k < K ; k++) {
            cin >> input;
            if(input == 'U')
                Answer += numbers(i--, j);
            else if(input == 'D')
                Answer += numbers(i++, j);
            else if(input == 'R')
                Answer += numbers(i, j++);
            else
                Answer += numbers(i, j--);
        }
        Answer += numbers(i, j);
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