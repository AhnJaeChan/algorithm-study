#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long int N;
    cin >> N;

    int point, i, j;
    long int answer = 0;

    for(i=1 ; i<=9 ; i++){
        if(N < pow(10, i)){
            point = i;
            break;
        }
    }

    for(i=0 ; i<point-1 ; i++)
        answer += (i+1) * (pow(10,i+1) - pow(10,i));

    answer += (point) * (N-pow(10,point-1)+1);

    cout << answer << endl;

    return 0;
}
