#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int city[101][101];

int main() {
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            city[i][j] = MAX_NUM;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = min(city[a][b], c);
    }
    for (int i = 1; i <= N; ++i)
        city[i][i] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (city[j][k] > city[j][i] + city[i][k]) {
                    city[j][k] = city[j][i] + city[i][k];
                }
            }
        }
    }

    

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (city[i][j] == MAX_NUM)
                city[i][j] = 0;
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }

}