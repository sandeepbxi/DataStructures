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
    void insertatend(node* &head,int val){
        node*temp=new node(val);
        node*t=head;
        while(t->next!=nullptr){
            t=t->next;
        }t->next=temp;
    }
    void insertinbetween(node* &head,int value,int pos){
        node*temp=new node(value);
        node*t=head;
        while(t->val!=pos){
            t=t->next;
        }
        temp->next=t->next;
        t->next=temp;
    }
    void deleteathead(node* &head){
        node*temp=head;
        head=temp->next;
        delete temp;
    }
    void deleteatend(node* &head){
        node*temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }
   void deletebyvalue(node* &head, int value) {
    if (head == nullptr) return;
    if (head->val == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr && temp->next->val != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        return;
    }
    node* del = temp->next;
    temp->next = del->next;
    delete del;
    }
    void searchvalue(node* &head,int value){
        node*temp=head;
        int cnt=1;
        while(temp->val!=value){
            temp=temp->next;
            cnt++;
        }cout<<value<<" Found at position "<<cnt<<endl;
    }
    void countsame(node* &head,int key){
        node*temp=head;
        int cnt=0;
        while(temp!=nullptr){
            if(temp->val==key){
                cnt++;
            }
            temp=temp->next;
        }
        cout<<"Count "<<cnt<<endl;
       while (true) {
        node* t = head;
        bool found = false;

        while (t != nullptr) {
            if (t->val == key) {
                deletebyvalue(head, key);
                found = true;
                break;
            }
            t = t->next;
        }

        if (!found) break;
    }
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
    countsame(head,1);
    display(head);
    
    
   
    return 0;
}
