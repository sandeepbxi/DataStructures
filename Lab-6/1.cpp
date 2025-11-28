#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=nullptr;
        next=nullptr;
    }
};

class cnode{
public:
    int data;
    cnode* next;
    cnode(int val){
        data=val;
        next=nullptr;
    }
};

void insertathead(node* &head,int val){
    node* n=new node(val);
    if(head==nullptr){
        head=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
}

void insertatend(node* &head,int val){
    if(head==nullptr){
        head=new node(val);
        return;
    }
    node* temp=head;
    while(temp->next) temp=temp->next;
    node* n=new node(val);
    temp->next=n;
    n->prev=temp;
}

void insertatposition(node* &head,int pos,int val){
    if(pos==1){
        insertathead(head,val);
        return;
    }
    node* temp=head;
    int c=1;
    while(c<pos-1 && temp){
        temp=temp->next;
        c++;
    }
    if(temp==nullptr){
        insertatend(head,val);
        return;
    }
    if(temp->next==nullptr){
        insertatend(head,val);
        return;
    }
    node* n=new node(val);
    n->next=temp->next;
    n->prev=temp;
    temp->next->prev=n;
    temp->next=n;
}

void deleteathead(node* &head){
    if(head==nullptr) return;
    node* temp=head;
    head=head->next;
    if(head) head->prev=nullptr;
    delete temp;
}

void deleteatend(node* &head){
    if(head==nullptr) return;
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    node* temp=head;
    while(temp->next) temp=temp->next;
    temp->prev->next=nullptr;
    delete temp;
}

void deleteatposition(node* &head,int pos){
    if(head==nullptr) return;
    if(pos==1){
        deleteathead(head);
        return;
    }
    node* temp=head;
    int c=1;
    while(c<pos && temp){
        temp=temp->next;
        c++;
    }
    if(temp==nullptr) return;
    if(temp->next==nullptr){
        deleteatend(head);
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}

void print(node* head){
    if(head==nullptr){
        cout<<"Empty"<<endl;
        return;
    }
    cout<<"Null<- ";
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"->Null"<<endl;
}

bool searchdll(node* head,int key){
    node* temp=head;
    while(temp){
        if(temp->data==key) return true;
        temp=temp->next;
    }
    return false;
}

int dllsize(node* head){
    int c=0;
    node* temp=head;
    while(temp){
        c++;
        temp=temp->next;
    }
    return c;
}

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
    cout<<head->data<<endl;
}

int main(){
    node* head=nullptr;
    cnode* chead=nullptr;
    int ch,x,pos,key;

    while(true){
        cout<<"\n1 Insert DLL Head\n2 Insert DLL End\n3 Insert DLL Position\n4 Delete DLL Head\n5 Delete DLL End\n6 Delete DLL Position\n7 Search DLL\n8 Print DLL\n9 DLL Size\n\n10 Insert CLL Head\n11 Insert CLL End\n12 Insert CLL After\n13 Delete CLL Head\n14 Delete CLL End\n15 Delete CLL Specific\n16 Search CLL\n17 Print CLL\n18 CLL Size\n\n0 Exit\n";
        cin>>ch;

        if(ch==0) break;

        if(ch==1){
            cin>>x; insertathead(head,x);
        }
        else if(ch==2){
            cin>>x; insertatend(head,x);
        }
        else if(ch==3){
            cin>>pos>>x; insertatposition(head,pos,x);
        }
        else if(ch==4){
            deleteathead(head);
        }
        else if(ch==5){
            deleteatend(head);
        }
        else if(ch==6){
            cin>>pos; deleteatposition(head,pos);
        }
        else if(ch==7){
            cin>>key;
            cout<<(searchdll(head,key)?"Found":"Not Found")<<endl;
        }
        else if(ch==8){
            print(head);
        }
        else if(ch==9){
            cout<<dllsize(head)<<endl;
        }
        else if(ch==10){
            cin>>x; cinserthead(chead,x);
        }
        else if(ch==11){
            cin>>x; cinsertend(chead,x);
        }
        else if(ch==12){
            cin>>key>>x; cinsertafter(chead,key,x);
        }
        else if(ch==13){
            cdeletehead(chead);
        }
        else if(ch==14){
            cdeleteend(chead);
        }
        else if(ch==15){
            cin>>key; cdeletespecific(chead,key);
        }
        else if(ch==16){
            cin>>key; 
            cout<<(csearch(chead,key)?"Found":"Not Found")<<endl;
        }
        else if(ch==17){
            cprint(chead);
        }
        else if(ch==18){
            cout<<csize(chead)<<endl;
        }
    }
    return 0;
}
