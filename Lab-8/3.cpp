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

Node* minNode(Node* r){
    while(r->left) r=r->left;
    return r;
}

Node* deleteBST(Node* r,int k){
    if(!r) return r;
    if(k<r->data) r->left=deleteBST(r->left,k);
    else if(k>r->data) r->right=deleteBST(r->right,k);
    else{
        if(!r->left) return r->right;
        else if(!r->right) return r->left;
        Node* t=minNode(r->right);
        r->data=t->data;
        r->right=deleteBST(r->right,t->data);
    }
    return r;
}

int maxDepth(Node* r){
    if(!r) return 0;
    int L=maxDepth(r->left);
    int R=maxDepth(r->right);
    return (L>R?L:R)+1;
}

int minDepth(Node* r){
    if(!r) return 0;
    int L=minDepth(r->left);
    int R=minDepth(r->right);
    if(!r->left || !r->right) return (L>R?L:R)+1;
    return (L<R?L:R)+1;
}

int main(){
    Node* root=NULL;
    root=insertBST(root,50);
    insertBST(root,30);
    insertBST(root,20);
    insertBST(root,40);
    insertBST(root,70);
    insertBST(root,60);
    insertBST(root,80);

    root=deleteBST(root,30);

    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
    return 0;
}
