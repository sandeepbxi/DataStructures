#include <iostream>
using namespace std;

class cnode{
public:
    int data;
    cnode* next;
    cnode(int val){
        data=val;
        next=nullptr;
    }
};

void cinserthead(cnode* &head,int val){
    cnode* n=new cnode(val);
    if(head==nullptr){
        head=n;
        n->next=n;
        return;
    }
    cnode* temp=head;
    while(temp->next!=head) temp=temp->next;
    temp->next=n;
    n->next=head;
    head=n;
}

void cinsertend(cnode* &head,int val){
    if(head==nullptr){
        head=new cnode(val);
        head->next=head;
        return;
    }
    cnode* temp=head;
    while(temp->next!=head) temp=temp->next;
    cnode* n=new cnode(val);
    temp->next=n;
    n->next=head;
}

void cinsertafter(cnode* &head,int key,int val){
    if(head==nullptr) return;
    cnode* temp=head;
    do{
        if(temp->data==key){
            cnode* n=new cnode(val);
            n->next=temp->next;
            temp->next=n;
            return;
        }
        temp=temp->next;
    }while(temp!=head);
}

void cdeletehead(cnode* &head){
    if(head==nullptr) return;
    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }
    cnode* temp=head;
    while(temp->next!=head) temp=temp->next;
    cnode* d=head;
    temp->next=head->next;
    head=head->next;
    delete d;
}

void cdeleteend(cnode* &head){
    if(head==nullptr) return;
    if(head->next==head){
        delete head;
        head=nullptr;
        return;
    }
    cnode* temp=head;
    while(temp->next->next!=head) temp=temp->next;
    cnode* d=temp->next;
    temp->next=head;
    delete d;
}

void cdeletespecific(cnode* &head,int key){
    if(head==nullptr) return;
    if(head->data==key){
        cdeletehead(head);
        return;
    }
    cnode* temp=head;
    while(temp->next!=head && temp->next->data!=key) temp=temp->next;
    if(temp->next->data==key){
        cnode* d=temp->next;
        temp->next=d->next;
        delete d;
    }
}

bool csearch(cnode* head,int key){
    if(head==nullptr) return false;
    cnode* temp=head;
    do{
        if(temp->data==key) return true;
        temp=temp->next;
    }while(temp!=head);
    return false;
}

int csize(cnode* head){
    if(head==nullptr) return 0;
    int c=0;
    cnode* temp=head;
    do{
        c++;
        temp=temp->next;
    }while(temp!=head);
    return c;
}

void cprint(cnode* head){
    if(head==nullptr){
        cout<<"Empty"<<endl;
        return;
    }
    cnode* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

void cprintrepeat(cnode* head){
    if(head==nullptr){
        cout<<"Empty"<<endl;
        return;
    }
    cnode* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<endl;
}

int main(){
    cnode* head=nullptr;

    cinserthead(head,20);
    cinsertend(head,100);
    cinsertend(head,40);
    cinsertend(head,80);
    cinsertend(head,60);

    cout<<"List: ";
    cprint(head);

    cout<<"Repeating head value: ";
    cprintrepeat(head);

    cout<<"Size: "<<csize(head)<<endl;

    return 0;
}
