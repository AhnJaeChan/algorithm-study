#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, input, i;
vector <int> numbers;

void print_divided(int test_number, int N);

int main() {
    cin >> T;
    for(i = 0 ; i < T ; i++) {
        cin >> input;
        numbers.push_back(input);
    }
    for(i = 0 ; i < T ; i++) {
        print_divided(i, numbers[i]);
    }
    return 0;
}

void print_divided(int test_number, int N) {
    string number = to_string(N);
    string A;
    string B;
    for(int i = 0 ; i < number.length() ; i++) {
        if(number[i] == '4') {
            A.append("3");
            B.append("1");
        }
        else {
            A.append(string(1, number[i]));
            B.append("0");
        }
    }
    cout << "Case #" << test_number + 1 << " : " << atoi(A.c_str()) << " " << atoi(B.c_str()) << endl;
    return;
}
