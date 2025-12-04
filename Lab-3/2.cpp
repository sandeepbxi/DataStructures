#include <iostream>
#include <string>
using namespace std;
class stack{
    int top;
    char arr[100];
    public:
      stack(){
        top=-1;
    }
     bool isfull(){
        return top==100-1;
    }
    bool isempty(){
        return top==-1;
    }
    void push(int x){
        arr[++top] = x;
    }
    char pop(){
        return arr[top--];
    }
};

string reverse(const string &str) {
    stack s;
    for(char c: str){
        s.push(c);
    }
    while(!s.isempty()){
        cout<<s.pop();
    }
    cout<<endl;
}
int main() {
    string input = "DataStructure";
    cout << "Original: " << input << endl;
    cout << "Reversed: ";
    cout<<reverse(input);
    return 0;
}

