#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int v){data=v;left=right=NULL;}
};

void preorder(Node* r){
    if(!r) return;
    cout<<r->data<<" ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r){
    if(!r) return;
    inorder(r->left);
    cout<<r->data<<" ";
    inorder(r->right);
}

void postorder(Node* r){
    if(!r) return;
    postorder(r->left);
    postorder(r->right);
    cout<<r->data<<" ";
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);

    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root);
    return 0;
}
