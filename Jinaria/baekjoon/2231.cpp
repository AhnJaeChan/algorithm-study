#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1234567890;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, P, ret = INF;
        cin >> N >> P;
        vector<int> skill_rating(N);
        for (int &a : skill_rating) {
            cin >> a;
        }
        sort(skill_rating.begin(), skill_rating.end(), greater<int>());
        for (int i = 0; i < N - P; i++) {
            int case_result = 0;
            for (int j = i + 1; j < i + P; j++) {
                case_result += skill_rating[i] - skill_rating[j];
            }
            ret = min(case_result, ret);
        }
        cout << "Case #1: " << ret << endl;
    }
}