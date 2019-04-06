#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int count = 0;
vector < vector <int> > processes;

void move_tower(int from, int to, int by, int number);

int main() {
    cin >> N;
    move_tower(1, 3, 2, N);
    cout << processes.size() << endl;
    for(int i = 0 ; i < processes.size() ; i++) {
        for(int j = 0 ; j < processes[i].size() ; j++) {
            printf("%d ", processes[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void move_tower(int from, int to, int by, int number) {
    if(number == 1) {
        vector <int> process;
        process.push_back(from);
        process.push_back(to);
        processes.push_back(process);
        return;
    }
    move_tower(from, by, to, number-1);
    vector <int> process;
    process.push_back(from);
    process.push_back(to);
    processes.push_back(process);
    move_tower(by, to, from, number-1);

    return;
}
// void move_tower(int from, int to, int number) {
//     if(number == 1) {
        // count++;
        // vector <int> process;
        // process.push_back(from);
        // process.push_back(to);
        // processes.push_back(process);
        // cout << from << " " << to << endl;
        // return;
//     }
//     if(from == 1 && to == 2) {
//         move_tower(1, 3, number - 1);
//         move_tower(1, 2, 1);
//         move_tower(3, 2, number - 1);
//     }
//     if(from == 1 && to == 3) {
//         move_tower(1, 2, number - 1);
//         move_tower(1, 3, 1);
//         move_tower(2, 3, number - 1);
//     }
//     if(from == 2 && to == 1) {
//         move_tower(2, 3, number - 1);
//         move_tower(2, 1, 1);
//         move_tower(3, 1, number - 1);
//     }
//     if(from == 2 && to == 3) {
//         move_tower(2, 1, number - 1);
//         move_tower(2, 3, 1);
//         move_tower(1, 3, number - 1);
//     }
//     if(from == 3 && to == 1) {
//         move_tower(3, 2, number - 1);
//         move_tower(3, 1, 1);
//         move_tower(2, 1, number - 1);
//     }
//     if(from == 3 && to == 2) {
//         move_tower(3, 1, number - 1);
//         move_tower(3, 2, 1);
//         move_tower(1, 2, number - 1);
//     }
//     return;
// }
