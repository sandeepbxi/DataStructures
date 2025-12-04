#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums){
    unordered_set<int> s;
    for(int x: nums){
        if(s.count(x)) return true;
        s.insert(x);
    }
    return false;
}

vector<int> commonElements(vector<int>& A, vector<int>& B){
    unordered_set<int> s(A.begin(), A.end());
    vector<int> ans;
    for(int x: B) if(s.count(x)) ans.push_back(x);
    return ans;
}

unordered_map<int,int> frequency(vector<int>& nums){
    unordered_map<int,int> m;
    for(int x: nums) m[x]++;
    return m;
}

int firstNonRepeating(vector<int>& nums){
    unordered_map<int,int> m;
    for(int x: nums) m[x]++;
    for(int x: nums) if(m[x]==1) return x;
    return -1;
}

struct Node{
    int val;
    Node* next;
    Node(int v){ val=v; next=NULL; }
};

bool hasCycle(Node* head){
    unordered_set<Node*> s;
    while(head){
        if(s.count(head)) return true;
        s.insert(head);
        head=head->next;
    }
    return false;
}

struct Tree{
    int val;
    Tree* left;
    Tree* right;
    Tree(int v){ val=v; left=right=NULL; }
};

bool hasDuplicateInTree(Tree* root, unordered_set<int>& s){
    if(!root) return false;
    if(s.count(root->val)) return true;
    s.insert(root->val);
    return hasDuplicateInTree(root->left,s) || hasDuplicateInTree(root->right,s);
}

bool containsDuplicateTree(Tree* root){
    unordered_set<int> s;
    return hasDuplicateInTree(root,s);
}

int main(){
    vector<int> v1 = {1,2,3,1};
    cout << containsDuplicate(v1) << endl;

    vector<int> A = {1,2,3,4};
    vector<int> B = {3,4,5,6};
    vector<int> c = commonElements(A,B);
    for(int x: c) cout << x << " ";
    cout << endl;

    vector<int> v2 = {2,3,4,3,4,2,3};
    auto m = frequency(v2);
    for(auto &p: m) cout << p.first << " " << p.second << endl;

    vector<int> v3 = {4,5,1,2,0,4};
    cout << firstNonRepeating(v3) << endl;

    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(3);
    h->next->next->next = h->next;
    cout << hasCycle(h) << endl;

    Tree* t = new Tree(5);
    t->left = new Tree(3);
    t->right = new Tree(7);
    t->left->left = new Tree(2);
    t->left->right = new Tree(3);
    cout << containsDuplicateTree(t) << endl;
  return 0;
}
