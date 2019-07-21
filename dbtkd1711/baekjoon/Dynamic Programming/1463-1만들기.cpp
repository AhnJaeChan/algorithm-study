#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> cache;

int min_operation(int number);

int main() {
    cin >> N;
    cache.assign(N + 1, 0);
    int answer = min_operation(N);
    cout << answer << endl;
    return 0;
}

int min_operation(int number) {
    int minimum;
    for(int i = 2 ; i <= number ; i++) {
        minimum = cache[i - 1];
        if(i % 3 == 0) {
            minimum = min(minimum, cache[i / 3]);
        }
        if(i % 2 == 0) {
            minimum = min(minimum, cache[i / 2]);
        }
        cache[i] = 1 + minimum;
    }
    return cache[number];
}
