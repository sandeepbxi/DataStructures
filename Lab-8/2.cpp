#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int v){data=v;left=right=NULL;}
};

Node* insertBST(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->data) r->left=insertBST(r->left,v);
    else if(v>r->data) r->right=insertBST(r->right,v);
    return r;
}

Node* searchRec(Node* r,int k){
    if(!r || r->data==k) return r;
    if(k<r->data) return searchRec(r->left,k);
    return searchRec(r->right,k);
}

Node* searchNonRec(Node* r,int k){
    while(r){
        if(k==r->data) return r;
        if(k<r->data) r=r->left;
        else r=r->right;
    }
    return NULL;
}

Node* minNode(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* maxNode(Node* r){
    while(r->right) r=r->right;
    return r;
}

Node* inorderSuccessor(Node* root, Node* x){
    Node* succ=NULL;
    while(root){
        if(x->data<root->data){
            succ=root;
            root=root->left;
        }else root=root->right;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    Node* pre=NULL;
    while(root){
        if(x->data>root->data){
            pre=root;
            root=root->right;
        }else root=root->left;
    }
    return pre;
}

int main(){
    Node* root=NULL;
    root=insertBST(root,50);
    insertBST(root,30);
    insertBST(root,70);
    insertBST(root,20);
    insertBST(root,40);
    insertBST(root,60);
    insertBST(root,80);

    Node* a=searchRec(root,40);
    Node* b=searchNonRec(root,70);

    cout<<minNode(root)->data<<endl;
    cout<<maxNode(root)->data<<endl;

    cout<<inorderSuccessor(root,root->left)->data<<endl;
    cout<<inorderPredecessor(root,root->right)->data<<endl;
    return 0;
}
