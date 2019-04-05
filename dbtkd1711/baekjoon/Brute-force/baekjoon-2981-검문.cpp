#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
vector<int> answer;

int main(){
    int N, input, i, j, remainder;
    cin >> N;
    for(i=0 ; i<N ; i++){
        cin >> input;
        number.push_back(input);
    }
    for(i=2 ; i<number.back() ; i++){
        remainder = number[0] % i;
        for(j=1 ; j<number.size() ; j++){
            if(remainder != number[j] % i)
                break;
        }
        if(j==number.size()){
            answer.push_back(i);
        }
    }
    for(i=0 ; i<answer.size() ; i++){
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
