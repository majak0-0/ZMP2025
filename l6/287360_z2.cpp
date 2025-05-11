#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val = 0) : data(val), left(nullptr), right(nullptr) {}

    ~Node() {
        delete left;
        delete right;
    }
};

int max(int a, int b) {
    return (a > b) ? a : b;
}


void printTreeHelper(Node* root, int space) {
    if (!root) return;

    space += 5;

    printTreeHelper(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->data;

    printTreeHelper(root->left, space);
}

void printTree(Node* root) {
    printTreeHelper(root, 0);
    cout << endl;
}

Node* mergeTrees(Node* t1, Node* t2, int rootVal) {
    Node* root = new Node(rootVal);
    root->left = t1;
    root->right = t2;
    return root;
}

Node* arrayToBalancedTree(int arr[], int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = arrayToBalancedTree(arr, start, mid - 1);
    root->right = arrayToBalancedTree(arr, mid + 1, end);
    return root;
}

bool contains(Node* root, int value) {
    if (!root) return false;
    if (root->data == value) return true;
    return contains(root->left, value) || contains(root->right, value);
}

int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n1, n2, r, s;
    cout << "Podaj kolejno n1, n2, r, s: ";
    cin >> n1 >> n2 >> r >> s;

    // wczytanie tablicy dla drzewa 1
    int* arr1 = new int[n1];
    cout << "Podaj " << n1 << " elementow dla pierwszego drzewa: ";
    for (int i = 0; i < n1; ++i) cin >> arr1[i];

    // wczytanie tablicy dla drzewa 2
    int* arr2 = new int[n2];
    cout << "Podaj " << n2 << " elementow dla drugiego drzewa: ";
    for (int i = 0; i < n2; ++i) cin >> arr2[i];

    Node* tree1 = arrayToBalancedTree(arr1, 0, n1 - 1);
    Node* tree2 = arrayToBalancedTree(arr2, 0, n2 - 1);

    // sklejenie drzew z nowym korzeniem
    Node* mergedTree = mergeTrees(tree1, tree2, r);

    cout << "\nPolaczone drzewo:\n";
    printTree(mergedTree);

    // Wyświetlenie właściwości drzewa
    cout << "Liczba wezlow: " << countNodes(mergedTree) << endl;
    cout << "Liczba lisci: " << countLeaves(mergedTree) << endl;
    cout << "Wysokosc drzewa: " << height(mergedTree) << endl;
    cout << "Czy " << s << " jest w drzewie? " << (contains(mergedTree, s) ? "Tak" : "Nie") << endl;

    // Zwolnienie pamięci
    delete[] arr1;
    delete[] arr2;
    delete mergedTree;

    return 0;
}