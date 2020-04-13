#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_NUM     123456789

int N;
int child[201];

int main() {
    ios::sync_with_stdio(false);
    
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> child[i];
    
    vector<int> d;
    d.push_back(child[1]);
    for (int i = 2; i <= N; ++i) {
        if (d.back() >= child[i]) {
            int k = lower_bound(d.begin(), d.end(), child[i]) - d.begin();
            d[k] = child[i];
        }
        else {
            d.push_back(child[i]);
        }
    }
    cout << N - d.size() << '\n';


    return 0;

}