#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int test = 0; test < T; test++) {
        int N, L;
        cin >> N >> L;
        vector<int> cipher(L);
        vector<int> text(L + 1);
        priority_queue<int, vector<int>, greater<int> > alphabet;
        vector<int> alpha;
        string abc(L + 1, 'a');
        string::iterator iter = abc.begin();

        for (int i = 0; i < L; i++) {
            cin >> cipher[i];
        }
        int a = 0, b = 0;
        for (int i = 2; i < cipher[0]; i++) {
            if (cipher[0] % i == 0) {
                a = i;
                b = cipher[0] / i;
                break;
            }
        }
        if (cipher[1] % a == 0) {
            text[0] = b;
            alphabet.push(b);
            for (int i = 1; i < L; i++) {
                text[i] = a;
                alphabet.push(a);
                text[i + 1] = cipher[i] / a;
                a = cipher[i] / a;
            }
            alphabet.push(a);
        }
        else {
            text[0] = a;
            alphabet.push(a);
            for (int i = 1; i < L; i++) {
                text[i] = b;
                alphabet.push(b);
                text[i + 1] = cipher[i] / b;
                b = cipher[i] / b;
            }
            alphabet.push(b);
        }
        while (!alphabet.empty()) {
            int c = alphabet.top();
            alpha.push_back(c);
            alphabet.pop();
        }
        for (int c : text) {
            for (int i = 0; i < 26; i++) {
                if (alpha[i] == c) {
                    *iter++ = 'A' + i;
                }
            }
        }
        cout << "Case #" << test + 1 << ": " << abc << endl;
    }
}