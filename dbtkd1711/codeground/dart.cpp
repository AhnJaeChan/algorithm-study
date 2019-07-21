#include <iostream>
#include <cmath>

using namespace std;

int T, N, input, i, j;
int A, B, C, D, E;
int x, y;
double distance;
int scores[20] = {6, 13, 4, 18, 1,
                  20, 5, 12, 9, 14,
                  11, 8, 16, 7, 19,
                  3, 17, 2, 15, 10};

double get_distance(double x, double y);
int get_score(double distance, int score);

int main() {
    cin >> T; 
    for(i = 0 ; i < T ; i++) {
        cin >> A >> B >> C >> D >> E;
        cin >> N;
        for(j = 0 ; j < N ; j++) {
            cin >> x >> y;
            distance = get_distance(x, y);
        }
    }
    return 0;
}

double get_distance(double x, double y) {
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    return distance;
}

int get_score(double distance, int score) {
    int multiply;
    if(distance < A)
        return 50;
}