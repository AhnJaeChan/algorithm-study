#include <iostream>
#include <vector>

using namespace std;

int C, n, input;
vector <int> line;
vector < vector <int> > area;
vector < vector <int> > reachable;

void is_reachable();

int main() {
    cin >> C;
    for(int i = 0 ; i < C ; i++) {
        cin >> n;
        reachable.assign(n, vector <int>(n, -1));
        reachable[0][0] = 1;
        for(int j = 0 ; j < n ; j ++) {
            for(int k = 0 ; k < n ; k++) {
                cin >> input;
                line.push_back(input);
            }
            area.push_back(line);
            line.clear();
        }
        is_reachable();
        area.clear();
    }
    return 0;
}

void is_reachable() {
    int move;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(reachable[i][j] == 1) {
                move = area[i][j];
                if(j + move < n)
                    reachable[i][j+move] = 1;
                if(i + move < n)
                reachable[i+move][j] = 1;
            }
        }
    }
    if(reachable[n-1][n-1] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return;
}
