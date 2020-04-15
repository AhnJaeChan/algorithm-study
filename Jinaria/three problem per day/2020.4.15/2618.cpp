#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_INT     1234567890

typedef struct{
    int x, y;
}Event;

int N, W;
Event first[1001], second[1001];
int d[1001][1001];
int p[1001][1001];


int dist(Event &a, Event &b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}


int main(){
    scanf("%d %d", &N, &W); 
    for(int i = 1; i <= W; ++i){
        scanf("%d %d", &first[i].x, &first[i].y);
        second[i] = first[i];
    }
    first[0] = {1, 1};
    second[0] = {N, N};
    for(int i = 0; i <= W; ++i){
        for(int j = 0; j <= W; ++j){
            d[i][j] = MAX_INT;
        }
    }
    d[0][0] = 0;
    
    int ans = MAX_INT;
    Event last = {0, 0};
    for(int i = 0; i < W; ++i){
        for(int j = 0; j < W; ++j){
            if(i > 0 && i == j)
                continue;
            int cur_case = max(i, j) + 1;
            if(d[cur_case][j] > d[i][j] + dist(first[cur_case], first[i])){
                d[cur_case][j] = d[i][j] + dist(first[cur_case], first[i]);
                p[cur_case][j] = cur_case - i;
            }
            if(d[i][cur_case] > d[i][j] + dist(second[cur_case], second[j])){
                d[i][cur_case] = d[i][j] + dist(second[cur_case], second[j]);
                p[i][cur_case] = j - cur_case;
            }
            if(cur_case == W){
                ans = min(ans, min(d[cur_case][j], d[i][cur_case]));
            }
        }
    }
    printf("%d\n", ans);
    vector<int> path;
    int x = 0, y = 0;
    for(int i = 0; i < W; ++i){
        if(d[i][W] == ans){
            x = i;
            y = W;
            break;
        }
        if(d[W][i] == ans){
            x = W;
            y = i;
            break;
        }
    }
    while(x > 0 || y > 0){
        if(p[x][y] > 0){
            path.push_back(1);
            x -= p[x][y];
        }
        else{
            path.push_back(2);
            y += p[x][y];
        }
    }
    
    for(auto it = path.rbegin(); it != path.rend(); ++it){
        printf("%d\n", *it);
    }


    
    return 0;
}