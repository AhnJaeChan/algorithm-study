#include <iostream>
#include <cstdio>

using namespace std;

int Answer;

const int MAX_STONE = 1000000;
const int INF = 1234567890;
int N, K;
int stone[MAX_STONE + 1];


int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        cin >> N;
        for (int i = 0; i < N; i++) scanf("%d", &stone[i]);
        cin >> K;
        stone[N] = INF;
        int curpos = 0;
        for (int i = 0; i < N; i++) {
            if (stone[i] - curpos <= K && stone[i + 1] - curpos > K) {
                curpos = stone[i];
                Answer++;
            }
            else if (stone[i] - curpos > K) {
                Answer = -1;
                break;
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }

    return 0;
}