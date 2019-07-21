#include <iostream>

using namespace std;

int main() {
    int ** a;
    a = new int * [50000];
    for(int i=0 ; i<50000;i++) {
        a[i] = new int[50000];
    }

    return 0;
}