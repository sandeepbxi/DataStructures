#include<iostream>
using namespace std;
class CircularQueue{
    int front;
    int rear;
    int arr[4];
    public:
        CircularQueue(){
            front=rear=-1;
        }
        bool empty(){
            return (front==-1);
        }
        bool full(){
            return ((rear+1)%4==front);
        }
        void enqueue(int val){
            if(full()){
                cout<<" Not enough Space in array to enqueue! "<<endl;
                return;
            }
            if(front==-1){
                front=rear=0;
            }
            else
                rear=(rear+1)%4;
            arr[rear]=val;
            cout<<val<<" Enqueued in array ! "<<endl;
            
        }
        void dequeue(){
            if(empty()){
                cout<<" Queue is empty  "<<endl;
                return;
            }
            cout<<arr[front]<<" Dequeued "<<endl;
            if(front==rear){
                front=rear=-1;
            }
            else
            front=(front+1)%4;
        }
        void peek(){
            if(empty()){
                cout<<" Queue is empty  "<<endl;
                return;
            }
            cout<<arr[front]<<" is peek "<<endl;
        }
        void display(){
            if(empty()){
                cout<<" Queue is empty  "<<endl;
                return;
            }
          int i = front;
          while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % 4;
          }
          cout << arr[rear] << endl;

        }
};
int main(){
    CircularQueue q;
    int choice,value;
    while (true) {
        cout << "\n---- Queue Menu ----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if (q.empty())
                cout << "Queue is EMPTY.\n";
            else
                cout << "Queue is NOT empty.\n";
            break;

        case 4:
            if (q.full())
                cout << "Queue is FULL.\n";
            else
                cout << "Queue is NOT full.\n";
            break;

        case 5:
            q.peek();
            break;

        case 6:
            q.display();
            break;

        case 7:
            exit(0);

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
