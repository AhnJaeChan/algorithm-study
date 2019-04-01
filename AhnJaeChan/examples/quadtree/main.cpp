#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string reverse(string::iterator &iter) {
    char front = *iter++;

    if (front != 'x') {
        return string(1, front);
    }

    string upper_left = reverse(iter);
    string upper_right = reverse(iter);
    string lower_left = reverse(iter);
    string lower_right = reverse(iter);

    return "x" + lower_left + lower_right + upper_left + upper_right;
}

int main() {
    ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        cout << "Failed to open file." << endl;
        return -1;
    }

    ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        cout << "Failed to open file." << endl;
        return -1;
    }

    int C;
    input_file >> C;

    for (int i = 0; i < C; i++) {
        string compressed;

        input_file >> compressed;

        string::iterator iter = compressed.begin();
        string decompressed = reverse(iter);

        output_file << decompressed << endl;
    }

    if (input_file.is_open()) {
        input_file.close();
    }

    if (output_file.is_open()) {
        output_file.close();
    }

    return 0;
}