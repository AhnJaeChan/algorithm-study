#include <iostream>
#include <vector>
#include <string>

using namespace std;

int C, N;
string W, filename;
vector <string> filenames;

int main() {
    cin >> C;
    for(int i = 0 ; i < C ; i++) {
        cin >> W >> N;
        for(int j = 0 ; j < N ; j++) {
            cin >> filename;
            filenames.push_back(filename);
        }
    }
    return 0;
}
