#include <iostream>

using namespace std;

int Answer;
long long a[100002];

int main(int argc, char** argv)
{
	int T, test_case, N, i;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
		a[0] = 0;
		for(i = 1 ; i <= N ; i++) {
			cin >> a[i];
		}
		a[i] = 0;

		Answer = 1;
		for(i = 1 ; i <= N ; i++) {
			if(a[i] > a[i-1] + 1)
				a[i] = a[i-1] + 1;
		}
		for(i = N ; i >= 1 ; i--) {
			if(a[i] > a[i+1] + 1)
				a[i] = a[i+1] + 1;
		    if(a[i] > Answer)
				Answer = a[i];
		}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
