#include <iostream>
#include <vector>

using namespace std;

int T, n, answer;
vector <int> cache;

int number_of_sum_method(int number);

int main() {
    cin >> T;
    for(int i = 0 ; i < T ; i++) {
        cin >> n;
        cache.assign(n + 1, 0);
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;
        answer = number_of_sum_method(n);
        cout << answer << endl;
    }
    return 0;
}

int number_of_sum_method(int number) {
    if(cache[number] != 0)
        return cache[number];

    cache[number] = number_of_sum_method(number - 1) + number_of_sum_method(number - 2) + number_of_sum_method(number - 3);

    return cache[number];
}
