#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool star_check(string wild, vector<int> &idx) {
    bool has_star = false;
    for (int i = 0; i < wild.length(); i++) {
        if (wild[i] == '*') { has_star = true; }
        else idx.push_back(i);
    }
    return has_star;
}

bool check(string wild, vector<int> idx, string file, bool has_star) {
    string::iterator wild_iter = wild.begin();
    string::iterator file_iter = file.begin();
    vector<int>::iterator idx_iter = idx.begin();
    if (has_star) {
        while (idx_iter != idx.end() && file_iter != file.end()) {
            if (*idx_iter == 0 && (wild[*idx_iter] != '?'&& wild[*idx_iter] != *file_iter)) {
                return false;
            }
            if (*idx_iter == wild.length() - 1 && (wild[*idx_iter] != '?' && wild[*idx_iter] != *(file.end() - 1))) {
                return false;
            }
            if (wild[*idx_iter] == '?' || wild[*idx_iter] == *file_iter) {
                idx_iter++;
                file_iter++;
            }
            else {
                file_iter++;
            }
        }
        if (idx_iter == idx.end()) {
            return true;
        }
        return false;
    }
    else {
        while (wild_iter != wild.end() && file_iter != file.end()) {
            if (*wild_iter == '?' || *wild_iter == *file_iter) {
                wild_iter++;
                file_iter++;
            }
            else {
                break;
            }
        }
        if (wild_iter == wild.end() && file_iter == file.end()) {
            return true;
        }
        return false;
    }
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        string wild_card;
        int file_num;
        cin >> wild_card >> file_num;
        vector<string> files(file_num);
        vector<string> right_files;
        vector<int> star_index;

        for (string &a : files) cin >> a;

        bool has_star = star_check(wild_card, star_index);

        for (string file : files) {
            if (check(wild_card, star_index, file, has_star)) {
                right_files.push_back(file);
            }
        }
        sort(right_files.begin(), right_files.end());
        for (string file : right_files) {
            cout << file << endl;
        }

    }
}