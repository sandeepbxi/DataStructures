#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char c) {
        data = c;
        prev = nullptr;
        next = nullptr;
    }
};

void insertEnd(Node* &head, char c) {
    Node* newnode = new Node(c);
    if(!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

bool isPalindrome(Node* head) {
    if(!head || !head->next) return true;

    Node* left = head;
    Node* right = head;

    while(right->next) right = right->next;

    while(left != right && right->next != left) {
        if(left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = nullptr;

    string s;
    cout << "Enter characters: ";
    cin >> s;

    for(char c : s)
        insertEnd(head, c);

    if(isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
