#include <iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int v){
        data=v;
        prev=nullptr;
        next=nullptr;
    }
};

int dllSize(DNode* head){
    int cnt=0;
    while(head!=nullptr){
        cnt++;
        head=head->next;
    }
    return cnt;
}

int main(){
    DNode* head=new DNode(10);
    head->next=new DNode(430);
    head->next->prev=head;
    head->next->next=new DNode(30);
    head->next->next->prev=head->next;
    head->next->next->next=new DNode(57);
    head->next->next->next->prev=head->next->next;
    cout<<dllSize(head);
}
