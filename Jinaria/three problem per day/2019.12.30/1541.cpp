#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    char str[100];
    scanf("%s", str);

    vector<int> operand, op;
    int i = 0, t = 0;
    while (str[i] != '\0') {
        if (str[i] <= '9' && str[i] >= '0') {
            t = t * 10 + str[i] - '0';
        }
        else {
            operand.push_back(t);
            op.push_back(str[i]);
            t = 0;
        }
        i++;
    }
    operand.push_back(t);
    int result = operand[0];
    bool flag = false;
    for (i = 0; i < op.size(); ++i) {
        if (op[i] == '-') {
            flag = true;
        }
        if (flag) {
            result -= operand[i + 1];
        }
        else {
            result += operand[i + 1];
        }
    }
    printf("%d\n", result);

}