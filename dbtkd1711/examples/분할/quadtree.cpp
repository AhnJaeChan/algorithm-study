#include <iostream>
#include <string>

using namespace std;

int C;
int index = 0;
string compression;
string answer;

string reverse();

int main() {
    cin >> C;
    for(int i = 0 ; i < C ; i++) {
        cin >> compression;
        answer = reverse();
        cout << answer << endl;
        index = 0;
    }
    return 0;
}

string reverse() {
    char head = compression[index];
    index++;
    if(head == 'b' || head == 'w')
        return string(1, head);
    string upper_left = reverse();
    string upper_right = reverse();
    string lower_left = reverse();
    string lower_right = reverse();
    return string("x") + lower_left + lower_right + upper_left + upper_right;
}
