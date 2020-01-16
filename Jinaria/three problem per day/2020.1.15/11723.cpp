#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define BIT_ALL     0b11111111111111111111
#define BIT_EMPTY   0

int main() {
    ios::sync_with_stdio(false);
    int M;
    cin >> M;
    int S = 0;
    string order;
    int num;
    while (M--) {
        cin >> order;
        if (!order.compare("add")) {
            cin >> num;
            S |= (1 << (num - 1));
        }
        else if (!order.compare("remove")) {
            cin >> num;
            S &= ~(1 << (num - 1));
        }
        else if (!order.compare("check")) {
            cin >> num;
            printf("%d\n", (S & (1 << (num - 1))) ? 1 : 0);
        }
        else if (!order.compare("toggle")) {
            cin >> num;
            S ^= (1 << (num - 1));
        }
        else if (!order.compare("all")) {
            S |= BIT_ALL;
        }
        else if (!order.compare("empty")) {
            S &= BIT_EMPTY;
        }
    }

}