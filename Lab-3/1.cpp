#include <iostream>
#include <string>
using namespace std;
class stack{
    int top;
    int size;
    int *arr;
    public:
stack(){
        top=-1;
        size=2;
        arr=new int[size];
    }
     bool isfull(){
        return top==size-1;
    }
    bool isempty(){
        return top==-1;
    }
    void push(int x){
        if(isfull()){
            cout<<"Overlflow"<<endl;
        }
        else {
        arr[++top]=x;
        cout<<x<<" pushed into stack"<<endl;
        }
    }
    void pop(){
        if(isempty()){
            cout<<"Underflow"<<endl;
        }
        else{
        cout<<arr[top--]<<" Popped out"<<endl;
    }
    }
    void peek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
        cout<<arr[top]<<" Is at peek"<<endl;
    }
    }
    void display(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<endl;
        }
    }
    }
};

int main() {
    stack s;
    s.push(10);
    s.push(9);
    s.push(8);
    s.display();
    s.peek();
    s.pop();
    s.display();
  s.pop();
  s.pop();
  s.pop();
    return 0;
}
