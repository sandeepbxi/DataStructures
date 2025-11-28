#include <iostream>
using namespace std;

class CNode{
public:
    int data;
    CNode* next;
    CNode(int v){
        data=v;
        next=nullptr;
    }
};

int cllSize(CNode* head){
    if(head==nullptr) return 0;
    int cnt=0;
    CNode* temp=head;
    do{
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    return cnt;
}

int main(){
    CNode* head=new CNode(20);
    CNode* n2=new CNode(40);
    CNode* n3=new CNode(60);

    head->next=n2;
    n2->next=n3;
    n3->next=head;

    cout<<cllSize(head);
}
