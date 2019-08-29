//
// Created by 안재찬 on 2019-08-20.
//

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Node {
public:
  int key;

  Node *next;
  Node *prev;

  explicit Node(int key) {
    this->key = key;
    next = prev = nullptr;
  }

  static void connect(Node *from, Node *to) {
    from->next = to;
    to->prev = from;
  }

  friend ostream &operator<<(ostream &, const Node &);
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  LinkedList() {
    head = new Node(INT32_MAX);
    tail = new Node(INT32_MAX);

    Node::connect(head, tail);
  }

  ~LinkedList() {
    Node *tmp;
    while (head != nullptr) {
      tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void push(int key) {
    Node *node = new Node(key);
    Node::connect(tail->prev, node);
    Node::connect(node, tail);
  }

  bool is_empty() {
    return head->next == tail;
  }

  Node *search(int key) {
    Node *cur = head->next;
    while (cur != tail) {
      if (key == cur->key) {
        return cur;
      }
      cur = cur->next;
    }
    return nullptr;
  }

  void remove(Node *node) {
    Node::connect(node->prev, node->next);
    delete node;
  }

  Node *before(Node *node) {
    return node->prev == head ? nullptr : node->prev;
  }

  Node *after(Node *node) {
    return node->next == tail ? nullptr : node->next;
  }

  Node *front() {
    return head->next;
  }

  Node *end() {
    return tail->prev;
  }

  friend ostream &operator<<(ostream &, const LinkedList &);
};

ostream &operator<<(ostream &os, const Node &node) {
  os << node.key;
  return os;
}

ostream &operator<<(ostream &os, const LinkedList &linked_list) {
  os << "head";
  Node *cur = linked_list.head->next;

  while (cur != linked_list.tail) {
    os << " -> " << *cur;
    cur = cur->next;
  }

  os << " -> tail";

  return os;
}

int weight[101][101];
int T, N, s;

int main(int argc, char *argv[]) {

  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    cin >> N;
    cin >> s;

    LinkedList l;
    int t[N];
    for (int i = 1; i < N; i++) {
      l.push(i);
      cin >> t[i];
    }
    l.push(N);

    for (int row = 1; row <= N; row++) {
      weight[row][row] = 0;
      for (int col = row + 1; col <= N; col++) {
        weight[row][col] = weight[col][row] = weight[row][col - 1] + t[col - 1];
      }
    }

    Node *cur = l.search(3);

    LinkedList shortest_path;

    while (!l.is_empty()) {
      Node *before = l.before(cur);
      Node *after = l.after(cur);

      if (before == nullptr) {
        before = after;
      } else if (after == nullptr) {
        after = before;
      }

      Node *target;

      if (before == nullptr && after == nullptr) {
        target = nullptr;
      } else {
        target = weight[cur->key][before->key] < weight[cur->key][after->key] ? before : after;
      }

      shortest_path.push(cur->key);
      l.remove(cur);
      cur = target;
    }

    int sum = 0;
    cur = shortest_path.front();
    while (cur != shortest_path.end()) {
      sum += (--N) * weight[cur->key][cur->next->key];
      cur = cur->next;
    }

    cout << sum << endl;
  }


  return 0;
}