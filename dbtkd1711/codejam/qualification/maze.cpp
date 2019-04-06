#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int T, N, i, j;
string input;
vector < pair<int, int> > rival;
vector < pair<int, int> > mine;

void find_path(int test_num);
int is_east(int index, vector< pair<int, int> > &v);

int main() {
    cin >> T;
    for(i = 0 ; i < T ; i++) {
        cin >> N;
        rival.push_back(make_pair(0, 0));
        mine.push_back(make_pair(0, 0));
        cin >> input;
        for(j = 0 ; j < 2*N -2 ; j++) {
            int row = rival.back().first;
            int col = rival.back().second;
            if(input[j] == 'E') {
                rival.push_back(make_pair(row, col+1));
            }
            else {
                rival.push_back(make_pair(row+1, col));
            }
        }
        find_path(i);
        rival.clear();
        mine.clear();
    }
    return 0;
}


void find_path(int test_num) {
    int E = 0, S = 0;
    for(int i = 0 ; i < 2*N - 2 ; i++) {
        int row = mine[i].first;
        int col = mine[i].second;
        if(rival[i].first == mine[i].first || rival[i].second == mine[i].second) {
            int temp = is_east(i, rival);
            if(temp == 1) {
                mine.push_back(make_pair(row+1, col));
            }
            else {
                mine.push_back(make_pair(row, col+1));
            }
        }
        else {
            if(E < N - 1) {
                mine.push_back(make_pair(row, col+1));
            }
            else {
                mine.push_back(make_pair(row+1, col));
            }
        }
    }
    cout << "Case #" << test_num + 1 << ": ";
    for(int i = 0 ; i < mine.size() - 1 ; i++) {
        int temp = is_east(i, mine);
        if(temp == 1) {
            cout << 'E';
        }
        else {
            cout << 'S';
        }
    }
    cout << endl;
    return;
}

int is_east(int index, vector< pair<int, int> > &v) {
    if(v[index].first != v[index+1].first)
        return 1;
    else
        return 0;
}
