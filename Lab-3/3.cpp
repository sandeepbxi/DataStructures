#include <iostream>
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
    char peek(){
        return arr[top];
    }
};

bool isBalanced(string expr) {
    stack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } 
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isempty()) return false;
            char top = s.peek();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.isempty();
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced"<<endl;
    else
        cout << "Not Balanced"<<endl;
 return 0;
}
