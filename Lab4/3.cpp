#include<iostream>
using namespace std;
class Queue{
    int size;
    int front;
    int rear;
    int *arr;
    public:
        Queue(int size){
            this->size=size;
            arr=new int[size];
            front=rear=-1;
        }
        bool empty(){
            return (front==-1);
        }
        bool full(){
            return ((rear+1)%size==front);
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
                rear=(rear+1)%size;
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
            front=(front+1)%size;
        }
        int peek(){
            return arr[front];
        }
        void display(){
            if(empty()){
                cout<<" Queue is empty  "<<endl;
                return;
            }
          int i = front;
          while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
          }
          cout << arr[rear] << endl;

        }

    void interleave(){
        int n;
     if(rear >= front)
        n = rear - front + 1;
     else
        n = size - front + rear + 1;


        if(n % 2 != 0){
            cout << "Queue must have even number of elements!\n";
            return;
        }

        Queue firsthalf(n/2);

        for(int i = 0; i < n/2; i++){
            firsthalf.enqueue(peek());
            dequeue();
        }

        while(!firsthalf.empty()){
            enqueue(firsthalf.peek());
            firsthalf.dequeue();

            enqueue(peek());
            dequeue();
        }
    }
};

int main(){
    Queue q(12);

    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    q.interleave();
    q.display();

    return 0;
}

