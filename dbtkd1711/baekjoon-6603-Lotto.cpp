#include <iostream>
#include <vector>

using namespace std;

int k;
int ans[6];
vector<int> S;

void dfs(int depth, int start);

int main(){
    int i, input;

    while(1){
        cin >> k;
        if(k==0)
            break;
        for(i=0 ; i<k ; i++){
            cin >> input;
            S.push_back(input);
        }
        dfs(0,0);
        S.clear();
        cout << endl;
    }
    return 0;
}

void dfs(int depth, int start){
    if(depth==6){
        for(int i=0 ; i<6 ; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=start ; i<k ; i++){
        ans[depth] = S[i];
        dfs(depth+1, i+1);
        ans[depth] = -1;
    }
}
