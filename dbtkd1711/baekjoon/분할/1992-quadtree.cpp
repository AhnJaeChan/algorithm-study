#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int N, i, j;
string input;
int a;
vector <int> line;
vector < vector <int> > image;

void divide(int row, int column, int size);

int main() {
    cin >> N;
    for(i = 0 ; i < N ; i++) {
        cin >> input;
        for(j = 0 ; j < input.length() ; j++) {
            line.push_back(input[j] - '0');
        }
        image.push_back(line);
        line.clear();
    }
    divide(0, 0, N);
    return 0;
}

void divide(int row, int column, int size) {
    int compare = image[row][column];
    int next_size = size / 2;
    for(i = row ; i < row + size ; i++) {
        for(j = column ; j < column + size ; j++) {
            if(compare != image[i][j]) {
                cout << "(";

                divide(row, column, next_size);
                divide(row, column + next_size, next_size);
                divide(row + next_size, column, next_size);
                divide(row + next_size, column + next_size, next_size);

                cout << ")";

                return;
            }
        }
    }
    if(compare == 0) {
        cout << "0";
    }
    else {
        cout << "1";
    }
    return;
}
