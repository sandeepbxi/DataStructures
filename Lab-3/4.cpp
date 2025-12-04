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
    void push(char x){
        arr[++top] = x;
    }
    char pop(){
        return arr[top--];
    }
    char peek(){
        return arr[top];
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(string infix) {
    stack s;
    string postfix = "";
    
    for (char ch : infix) {
if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
    postfix += ch;
}

        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.isempty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.isempty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.peek();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isempty()) {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
