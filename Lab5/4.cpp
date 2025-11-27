#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
    node* head;
    public:
    node(int val){
        this->val=val;
        this->next=nullptr;
        this->head=nullptr;
    }
};
    void insertathead(node* &head,int val){
        if(head==nullptr) {
            head=new node(val);
            head->next=nullptr;
        }
        node*temp=new node(val);
        temp->next=head;
        head=temp;
    }
    void reverse(node* &head){
        node*temp=head;
        node*next=nullptr;
        node*prev=nullptr;
        while(temp!=nullptr){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        head=prev;
    }
    void display(node* &head){
        if(head==nullptr){
            cout<<"List is empty "<<endl;
        }
        node*temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<"->";
            temp=temp->next;
        }cout<<"Null"<<endl;
    }
int main(){
    node*head=new node(1);
    insertathead(head,3);
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,1);
    insertathead(head,2);
    insertathead(head,1);
    display(head);
    reverse(head);
    display(head);
    
    
   
    return 0;
}
