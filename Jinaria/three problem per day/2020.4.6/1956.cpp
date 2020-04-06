#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789


int city[401][401];

int main() {
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i <= V; ++i) {
        for (int j = 0; j <= V; ++j) {
            city[i][j] = MAX_NUM;
        }
        //city[i][i] = 0;
    }
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        city[a][b] = c;
    }
    
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            for (int k = 1; k <= V; ++k) {
                if (city[j][k] > city[j][i] + city[i][k]) {
                    city[j][k] = city[j][i] + city[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (city[j][j] > city[j][i] + city[i][j]) {
                city[j][j] = city[j][i] + city[i][j];
            }
        }
    }

    int ans = MAX_NUM;
    for (int i = 1; i <= V; ++i) {
        ans = min(ans, city[i][i]);
    }
    if (ans == MAX_NUM) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}