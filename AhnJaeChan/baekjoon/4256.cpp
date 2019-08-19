//
// Created by 안재찬 on 2019-08-19.
//
#include <iostream>

using namespace std;

/**
 * Data structures
 */
class Node {
public:
  int key;
  Node *left;
  Node *right;

  explicit Node(int key) {
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class Queue {
public:
  int size;
  int front;
  int *arr;

  Queue(int size, int *arr) {
    this->size = size;
    this->front = 0;
    this->arr = arr;
  }

  int deqeue() {
    return front < size ? arr[front++] : -1;
  }

  int get_front() {
    return arr != nullptr ? arr[front] : -1;
  }
};

/**
 * Global variables
 */
int T, N;

int inorder[1000];
int preorder[1000];
Queue *q;

/**
 * Utility functions
 */
int linear_search(int key, int left, int right) {
  while (left <= right) {
    if (inorder[left] == key) {
      return left;
    }
    left++;
  }

  return -1;
}

Node *build_tree(int cur, int left, int right) {
  int idx = linear_search(cur, left, right);
  if (idx == -1) {
    // Not found
    return nullptr;
  }

  // Dequeue only when found!
  q->deqeue();

  Node *parent = new Node(cur);

  parent->left = build_tree(q->get_front(), left, idx - 1);
  parent->right = build_tree(q->get_front(), idx + 1, right);

  return parent;
}

void delete_tree(Node *node) {
  if (node == nullptr) {
    return;
  }

  if (node->left != nullptr) {
    delete_tree(node->left);
  }
  if (node->right != nullptr) {
    delete_tree(node->right);
  }
  delete node;
}

void postorder(Node *node) {
  if (node == nullptr) {
    return;
  }

  if (node->left != nullptr) {
    postorder(node->left);
  }
  if (node->right != nullptr) {
    postorder(node->right);
  }
  cout << node->key << " ";
}

int main(int argc, char *argv[]) {
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    cin >> N;

    // Preorder input
    for (int i = 0; i < N; i++) {
      cin >> preorder[i];
    }
    q = new Queue(N, preorder);

    // Inorder input
    for (int i = 0; i < N; i++) {
      cin >> inorder[i];
    }

    Node *root = build_tree(q->get_front(), 0, N - 1);
    postorder(root);
    cout << endl;

    delete_tree(root);
    delete q;
  }

  return 0;
}
