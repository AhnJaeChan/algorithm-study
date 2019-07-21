#include <iostream>
#include <string.h>

using namespace std;

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

int Answer, N;

int solve(int ** a, int ** check) {
    int i = 0, j = 0;
    int cnt = 0;
    int direction = RIGHT;

    while(1) {
        if(i < 0 || i >= N || j < 0 || j >= N)
            break;
        if(a[i][j] == 0) {
            switch(direction) {
                case UP:
                    i--;
                    break;
                case DOWN:
                    i++;
                    break;
                case RIGHT:
                    j++;
                    break;
                case LEFT:
                    j--;
                    break;
            }
        }
        else if(a[i][j] == 1) {
            if(check[i][j] == 0) {
                cnt++;
                check[i][j] = 1;
            }
            switch(direction) {
                case UP:
                    direction = RIGHT;
                    j++;
                    break;
                case DOWN:
                    direction = LEFT;
                    j--;
                    break;
                case RIGHT:
                    direction = UP;
                    i--;
                    break;
                case LEFT:
                    direction = DOWN;
                    i++;
                    break;
            }
        }
        else {
            if(check[i][j] == 0) {
                cnt++;
                check[i][j] = 1;
            }
            switch(direction) {
                case UP:
                    direction = LEFT;
                    j--;
                    break;
                case DOWN:
                    direction = RIGHT;
                    j++;
                    break;
                case RIGHT:
                    direction = DOWN;
                    i++;
                    break;
                case LEFT:
                    direction = UP;
                    i--;
                    break;
            }

        }
    }
    return cnt;
};

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> N;

        int ** a = new int * [N];
        for(int i = 0 ; i < N ; i++) {
            a[i] = new int[N];
        }

        char str[1001] = "";
        for(int i = 0 ; i < N ; i++) {
            cin >> str;
            for(int j = 0 ; j < N ; j++) {
                a[i][j] = (int)str[j] - 48;
            }
        }

        int ** check = new int * [N];
        for(int i = 0 ; i < N ; i++) {
            check[i] = new int[N];
            memset(check[i], 0, sizeof(int)*N);
        }
		Answer = solve(a, check);

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
        for(int i = 0 ; i < N ; i++) {
            delete [] a[i];
            delete [] check[i];
        }
        delete [] a;
        delete [] check;
	}

	return 0;
}