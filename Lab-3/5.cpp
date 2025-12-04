#include <iostream>
#include <cmath>
using namespace std;
class stack{
    int top;
    int arr[100];
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
    int pop(){
        return arr[top--];
    }
    int peek(){
        return arr[top];
    }
};

int evaluatePostfix(string postfix) {
    stack s;
    
    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int value2 = s.peek(); s.pop();
            int value1 = s.peek(); s.pop();
            switch (ch) {
                case '+': s.push(value1 + value2); break;
                case '-': s.push(value1 - value2); break;
                case '*': s.push(value1 * value2); break;
                case '/': s.push(value1 / value2); break;
                case '^': s.push(pow(value1, value2)); break;
            }
        }
    }
    return s.peek();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (digits): ";
    cin >> postfix;
    cout << "Evaluation: " << evaluatePostfix(postfix) << endl;
    return 0;
}
