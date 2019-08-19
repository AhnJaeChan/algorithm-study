#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> multiply_single(vector<char> &num, char single_num) {
    int operand = single_num - '0';
    for (auto digit = num.begin(); digit != num.end(); digit++) {
        int val = *digit - '0';
    }
}

vector<char> multiply(vector<char> &num1, vector<char> &num2) {
    vector<char> result;

    auto iter1 = num1.begin();
    auto iter2 = num2.begin();

    if (num1.size() < num2.size()) {
        swap(iter1, iter2);
    }

    int cnt = 0;

    for (auto j = iter2; j != num2.end(); ++j, ++cnt) {
        for (auto i = iter1; i != num1.end(); ++i) {
            cout << *i;
        }
        cout << endl << cnt << ", " << *j << endl;
    }

    return result;
}

int main() {
    vector<char> a{'2', '9', '5', '1', '4', '1', '.', '3'};

    multiply(a, a);

    return 0;
}