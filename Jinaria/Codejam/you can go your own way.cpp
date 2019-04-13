#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int test = 0; test < T; test++) {
        int N;
        string lydia;
        cin >> N >> lydia;
        string my_path(lydia);
        string::iterator my_iter = my_path.begin();
        for (char a : lydia) {
            if (a == 'E') {
                *my_iter++ = 'S';
            }
            else {
                *my_iter++ = 'E';
            }
        }
        cout << "Case #" << test + 1 << ": " << my_path << endl;
    }
}