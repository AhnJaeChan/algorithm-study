#include <iostream>

using namespace std;

int Answer, N, K;

int solve(int * a) {
    int i = 0;
    int cnt = 0;
    int index = 0;
    int flag = 0;
    for(i = 1 ; i <= N ; i++) {
        if(a[i] - a[index] <= K) {
            flag = 1;
        }
        if(a[i] - a[index] > K && flag == 1) {
            index = i - 1;
            cnt++;
            flag = 0;
            i--;
        }
        if(a[i] - a[index] > K && flag == 0) {
            return -1;
        }
    }

    return cnt + 1;
};

int main(int argc, char** argv)
{
	int T, test_case, i;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;
        int * a = new int[N+1];
        a[0] = 0;
        for(i = 1 ; i <= N ; i++) {
            cin >> a[i];
        }
        cin >> K;

		Answer = solve(a);
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}