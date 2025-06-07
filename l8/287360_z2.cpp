#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdexcept>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* copyTree(const Node* other) {
        if (!other) return nullptr;
        Node* newNode = new Node(other->value);
        newNode->left = copyTree(other->left);
        newNode->right = copyTree(other->right);
        return newNode;
    }

    static Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    static Node* combineNodes(const Node* a, const Node* b, const function<int(int, int)>& op) {
        if (a == nullptr && b == nullptr) {
            return nullptr;
        }
        if (a == nullptr || b == nullptr) {
            throw runtime_error("Trees are not isomorphic in combineNodes");
        }
        Node* newNode;
        newNode = new Node(op(a->value, b->value));
        newNode->left = combineNodes(a->left, b->left, op);
        newNode->right = combineNodes(a->right, b->right, op);
        return newNode;
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        clear(root);
    }

    BinaryTree(const BinaryTree& other) {
        root = copyTree(other.root);
    }

    BinaryTree& operator=(const BinaryTree& other) {
        if (this != &other) {
            clear(root);
            root = copyTree(other.root);
        }
        return *this;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    [[nodiscard]] const Node* getRoot() const {
        return root;
    }

    static bool isIsomorphic(const Node* a, const Node* b) {
        if (a == nullptr && b == nullptr) {
            return true;
        }
        if (a == nullptr || b == nullptr) {
            return false;
        }
        return isIsomorphic(a->left, b->left) && isIsomorphic(a->right, b->right);
    }

    int& operator[](int index) {
        if (index < 0) {
            throw out_of_range("Negative index");
        }

        queue<Node*> q;
        if (root) q.push(root);
        int count = 0;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (count == index) {
                return current->value;
            }
            count++;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        throw out_of_range("Index out of range");
    }

    const int& operator[](int index) const {
        if (index < 0) {
            throw out_of_range("Negative index");
        }

        queue<const Node*> q;
        if (root) q.push(root);
        int count = 0;

        while (!q.empty()) {
            const Node* current = q.front();
            q.pop();

            if (count == index) {
                return current->value;
            }
            count++;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        throw out_of_range("Index out of range");
    }

    friend ostream& operator<<(ostream& os, const BinaryTree& tree);
    friend BinaryTree operator+(const BinaryTree& t1, const BinaryTree& t2);
    friend BinaryTree operator-(const BinaryTree& t1, const BinaryTree& t2);
};

ostream& operator<<(ostream& os, const BinaryTree& tree) {
    if (!tree.root) return os;

    queue<BinaryTree::Node*> q;
    q.push(tree.root);

    while (!q.empty()) {
        BinaryTree::Node* current = q.front();
        q.pop();

        os << current->value;
        if (!q.empty() || current->left || current->right) {
            os << " ";
        }

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return os;
}

BinaryTree operator+(const BinaryTree& t1, const BinaryTree& t2) {
    BinaryTree result;
    result.root = BinaryTree::combineNodes(t1.root, t2.root, [](int a, int b) { return a + b; });
    return result;
}

BinaryTree operator-(const BinaryTree& t1, const BinaryTree& t2) {
    BinaryTree result;
    result.root = BinaryTree::combineNodes(t1.root, t2.root, [](int a, int b) { return a - b; });
    return result;
}

int main() {
    int n1;
    cin >> n1;
    vector<int> values1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> values1[i];
    }

    int n2;
    cin >> n2;
    vector<int> values2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> values2[i];
    }

    BinaryTree t1, t2;
    for (int x : values1) t1.insert(x);
    for (int x : values2) t2.insert(x);

    if (BinaryTree::isIsomorphic(t1.getRoot(), t2.getRoot())) {
        cout << "IZOMORFICZNE: TAK" << endl;
        BinaryTree t3 = t1 + t2;
        BinaryTree t4 = t1 - t2;
        cout << t3 << endl;
        cout << t4 << endl;
    } else {
        cout << "IZOMORFICZNE: NIE" << endl;
    }

    return 0;
}