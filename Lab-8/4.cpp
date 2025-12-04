#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int v){data=v;left=right=NULL;}
};

bool isBSTUtil(Node* r,int minv,int maxv){
    if(!r) return true;
    if(r->data<minv || r->data>maxv) return false;
    return isBSTUtil(r->left,minv,r->data-1) &&
           isBSTUtil(r->right,r->data+1,maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root,-1000000,1000000);
}

int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(30);

    cout<<isBST(root);
    return 0;
}
