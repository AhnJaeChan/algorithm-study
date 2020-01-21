#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


class Queue {
private:
    int length;
    int arr[2000001];
    int f;
    int rear;
public:
    Queue() :length(0), f(0), rear(-1) {

    }
    void push(int num) {
        length++;
        arr[++rear] = num;
    }
    int pop() {
        if (length == 0)
            return -1;
        length--;
        return arr[f++];
    }
    int front() {
        if (length == 0)
            return -1;
        return arr[f];
    }
    int back() {
        if (length == 0)
            return -1;
        return arr[rear];
    }
    int empty() {
        return (length == 0 ? 1 : 0);
    }
    int size() {
        return length;
    }
};


int main() {
    int N;
    scanf("%d", &N);
    Queue q;
    char op[6];
    int num;
    while (N--) {
        scanf("%s", op);
        if (!strcmp(op, "push")) {
            scanf("%d", &num);
            q.push(num);
        }
        else if (!strcmp(op, "pop")) {
            printf("%d\n", q.pop());
        }
        else if (!strcmp(op, "size")) {
            printf("%d\n", q.size());
        }
        else if (!strcmp(op, "empty")) {
            printf("%d\n", q.empty());
        }
        else if (!strcmp(op, "front")) {
            printf("%d\n", q.front());
        }
        else if (!strcmp(op, "back")) {
            printf("%d\n", q.back());
        }
    }

}