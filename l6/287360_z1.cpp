#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* CreateList(int n) {
    if (n <= 0) return nullptr;
    cout << "Podaj pierwsza wartosc listy: ";
    int val;
    cin >> val;
    Node* head = new Node(val);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        cout << "Podaj " << i + 1 << " wartosc listy: ";
        cin >> val;
        current->next = new Node(val);
        current = current->next;
    }
    return head;
}

// Dzieli liste na pol i zwraca poczatek drugiej polowy
Node* Split(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* second = slow->next;
    slow->next = nullptr;
    return second;
}

// Scalanie dwoch posortowanych list jednokierunkowych
Node* Merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

Node* MergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* second = Split(head);
    Node* left = MergeSort(head);
    Node* right = MergeSort(second);
    return Merge(left, right);
}

void PrintList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

void DeleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    cout << "Podaj dlugosc listy: ";
    int n;
    cin >> n;
    Node* head = CreateList(n);
    cout << "Nieposortowana lista: ";
    PrintList(head);
    head = MergeSort(head);
    cout << "Posortowana lista: ";
    PrintList(head);
    DeleteList(head);
    return 0;
}