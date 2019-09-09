//
// Created by 안재찬 on 2019-08-19.
//

#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

class Node {
public:
  int key;
  int size;

  Node *next;
  Node *prev;

  Node *up;
  Node *down;

  enum Connect {
    UP_DOWN,
    NEXT_PREV
  };

  explicit Node(int key) {
    this->key = key;
    size = 1;

    next = prev = up = down = nullptr;
  }

  int increment() { return ++size; }

  int decrement() { return --size; }

  bool is_empty() { return 0 == size; }

  static void connect(Node *from, Node *to, Connect con) {
    if (UP_DOWN == con) {
      from->up = to;
      to->down = from;
    } else {
      from->next = to;
      to->prev = from;
    }
  }

  friend ostream &operator<<(ostream &, const Node &);
};

class LinkedList {
public:
  int level;

  Node *head;
  Node *tail;

  LinkedList *above_;
  LinkedList *below_;

  LinkedList() {
    head = new Node(INT32_MIN);
    tail = new Node(INT32_MAX);

    Node::connect(head, tail, Node::NEXT_PREV);

    above_ = below_ = nullptr;
  }

  ~LinkedList() {
    Node *tmp;
    while (head != nullptr) {
      tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  LinkedList *above() const {
    return above_;
  }

  LinkedList *below() const {
    return below_;
  }

  Node *search(Node *start, int key) {
    Node *cur = start;
    while (cur->key < key) {
      cur = cur->next;
    }

    return cur->prev == nullptr ? head : cur->prev;
  }

  void insert(Node *prev, int key) {
    if (prev->key == key && prev != head) {
      prev->increment();
    } else {
      Node *next = prev->next;
      Node *node = new Node(key);
      Node::connect(prev, node, Node::NEXT_PREV);
      Node::connect(node, next, Node::NEXT_PREV);
    }
  }

  bool is_empty() {
    return head->next == tail;
  }

  static void connect(LinkedList *from, LinkedList *to) {
    Node::connect(from->head, to->head, Node::UP_DOWN);
    Node::connect(from->tail, to->tail, Node::UP_DOWN);
    from->above_ = to;
    to->below_ = from;
  }

  friend ostream &operator<<(ostream &, const LinkedList &);
};

class SkipList {
public:
  int level;
  LinkedList *list;

  enum Order {
    MIN,
    MAX
  };

  explicit SkipList(int level) : level(level) {
    srand(time(nullptr));

    try {
      this->list = new LinkedList[this->level];

      for (int i = 0; i < level; i++) {
        this->list[i].level = i;
      }

      for (int i = 0; i < level - 1; i++) {
        LinkedList::connect(&list[i], &list[i + 1]);
      }
    } catch (bad_alloc &exc) {
      this->list = nullptr;
    }
  }

  ~SkipList() {
    delete[] list;
  }

  LinkedList *top() const { return level > 0 ? &list[level - 1] : nullptr; }

  LinkedList *bottom() const { return list != nullptr ? &list[0] : nullptr; }

  int fetch(Order order) const {
    Node *node = Order::MIN == order ? bottom()->head->next : bottom()->tail->prev;
    return node->key;
  }

  bool is_empty() const { return bottom()->is_empty(); }

  void insert(int key) {
    Node *path[level];
    Node *node = search(key, path);

    // Found, increment size of node.
    // Special case on INT32_MAX handled by checking if next is tail.
    if (node->next->key == key && node->next != bottom()->tail) {
      node = node->next;
      while (node != nullptr) {
        node->increment();
        node = node->up;
      }
      return;
    }

    // Not found, new node is needed.
    int height = rand() % level;
    for (int i = 0; i <= height; i++) {
      list[i].insert(path[i], key);
    }

    for (int i = 0; i < height; i++) {
      Node::connect(path[i]->next, path[i + 1]->next, Node::UP_DOWN);
    }
  }

  void remove(Order order) {
    if (is_empty()) {
      return;
    }

    Node *node = Order::MIN == order ? bottom()->head->next : bottom()->tail->prev;
    node->decrement();

    if (node->is_empty()) {
      // Remove all of its upper nodes
      Node *tmp;

      while (node != nullptr) {
        tmp = node->up;
        Node::connect(node->prev, node->next, Node::NEXT_PREV);
        delete node;
        node = tmp;
      }
    } else {
      // Decrement size for its upper nodes
      node = node->up;
      while (node != nullptr) {
        node->decrement();
        node = node->up;
      }
    }
  }

  Node *search(int key, Node *path[]) {
    LinkedList *l = top();
    Node *cur = l->head;
    while (l != bottom()) {
      path[l->level] = l->search(cur, key);
      if (path[l->level] == nullptr) {
        cout << "TEST" << endl;
        exit(-1);
      }
      cur = path[l->level]->down;
      l = l->below();
    }
    path[l->level] = l->search(cur, key);
    return path[l->level];
  }

  friend ostream &operator<<(ostream &, const SkipList &);
};

ostream &operator<<(ostream &os, const Node &node) {
  os << "(" << node.key << ", " << node.size << ")";
  return os;
}

ostream &operator<<(ostream &os, const LinkedList &linked_list) {
  os << "[Lv." << linked_list.level << "] head";
  Node *cur = linked_list.head->next;

  while (cur != linked_list.tail) {
    os << " -> " << *cur;
    cur = cur->next;
  }

  os << " -> tail";

  return os;
}

ostream &operator<<(ostream &os, const SkipList &skip_list) {
  LinkedList *cur = skip_list.top();

  while (cur != nullptr) {
    os << *cur << endl;
    cur = cur->below();
  }

  return os;
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++) {
    int k;
    cin >> k;

    auto *skip_list = new SkipList((int) log2(k));

    for (int i = 0; i < k; i++) {
      char cmd;
      int option;
      cin >> cmd >> option;

      switch (cmd) {
        case 'I': {
          skip_list->insert(option);
          break;
        }
        case 'D': {
          const SkipList::Order order = (1 == option ? SkipList::Order::MAX : SkipList::Order::MIN);
          skip_list->remove(order);
          break;
        }
        default: {
          delete skip_list;
          return -1;
        }
      }
    }

    if (skip_list->is_empty()) {
      cout << "EMPTY" << endl;
    } else {
      cout << skip_list->fetch(SkipList::Order::MAX) << " " << skip_list->fetch(SkipList::Order::MIN) << endl;
    }

    delete skip_list;
  }

  return 0;
}
