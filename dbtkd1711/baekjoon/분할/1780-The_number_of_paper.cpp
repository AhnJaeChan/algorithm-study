#include <iostream>
#include <vector>

using namespace std;

int N, i, j, input;
int negative = 0, zero = 0, positive = 0;

vector <int> line;
vector < vector <int> > paper;

void count(int row, int column, int size);

int main() {
    cin >> N;
    for(i = 0 ; i < N ; i++) {
        for(j = 0 ; j < N ; j++) {
            cin >> input;
            line.push_back(input);
        }
        paper.push_back(line);
        line.clear();
    }

    count(0, 0, N);
    cout << negative << endl;
    cout << zero << endl;
    cout << positive << endl;

    return 0;
}

void count(int row, int column, int size) {
    int compare = paper[row][column];
    int next = size / 3;
    for(i = row ; i < row + size ; i++) {
        for(j = column ; j < column + size ; j++) {
            if(compare != paper[i][j]) {
                for(int k = row ; k < row + size ; k = k + next)
                    for(int l = column ; l < column + size ; l = l + next)
                        count(k, l, next);
                return;
            }
        }
    }
    if(compare == -1)
        negative++;
    else if(compare == 0)
        zero++;
    else if(compare == 1)
        positive++;

    return;
}
