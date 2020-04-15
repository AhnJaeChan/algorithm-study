#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> friends;

bool comp(vector<int> &a, vector<int> &b){
    return a.size() > b.size();
}

int main(){
    scanf("%d", &N);
    friends.resize(N + 1);
    int u, v;
    for(int i = 1; i <= N; ++i)
        friends[i].push_back(i);
    for(int i = 0; i < N - 1; ++i){
        scanf("%d %d", &u, &v);
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
    sort(friends.begin(), friends.end(), comp);
    for(int i = 0; i < N; ++i){
        printf("%d : %d\n", friends[i][0], friends[i].size());
    }


    return 0;
}