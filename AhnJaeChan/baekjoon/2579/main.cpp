#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int>::size_type N;
    int pi;

    cin >> N;

    vector<int> p;
    vector<pair<int, int> > s; // first = steps took before, second = max score for step i

    p.reserve(N);
    s.reserve(N);

    for (vector<int>::size_type i = 0; i < N; ++i) {
        cin >> pi;
        p.push_back(pi);
    }

    if (N == 1) {
        cout << p[0];
        return 0;
    }

    s.emplace_back(make_pair(0, p[0]));
    s.emplace_back(make_pair(1, p[0] + p[1]));

    if (p[0] < p[1]) {
        s.emplace_back(make_pair(1, p[1] + p[2]));
    } else {
        s.emplace_back(make_pair(2, p[0] + p[2]));
    }

    for (vector<int>::size_type i = 3; i < N; ++i) {
        if (max(s[i - 1].second, s[i - 2].second) == s[i - 1].second) {
            if (s[i - 1].first == 1) {
                if (s[i - 2].second < s[i - 3].second + p[i - 1]) {
                    s.emplace_back(make_pair(1, s[i - 3].second + p[i - 1] + p[i]));
                } else {
                    s.emplace_back(make_pair(2, s[i - 2].second + p[i]));
                }
            } else {
                s.emplace_back(make_pair(1, s[i - 1].second + p[i]));
            }
        } else {
            s.emplace_back(make_pair(2, s[i - 2].second + p[i]));
        }
    }

    cout << s[N - 1].second << endl;

    return 0;
}