#include <iostream>
#include <vector>

using namespace std;

int C, N;
vector <int> sequence;
vector <int> cache;
int input;

int find_max_lis(int start);

int main() {
    cin >> C;
    for(int i = 0 ; i < C ; i++) {
        cin >> N;
        cache.assign(N, -1);
        for(int j = 0 ; j < N ; j++) {
            cin >> input;
            sequence.push_back(input);
        }
        int answer = 0;
        for(int j = 0 ; j < N ; j++) {
            answer = max(answer, find_max_lis(j));
        }
        cout << answer << endl;
        sequence.clear();
    }
    return 0;
}

int find_max_lis(int start) {
    int ret = cache[start];

    if(ret != -1)
        return ret;

    ret = 1;
    for(int next = start + 1 ; next < N ; next++) {
        if(sequence[start] < sequence[next])
            ret = max(ret, find_max_lis(next) + 1);
    }

    return ret;
}
