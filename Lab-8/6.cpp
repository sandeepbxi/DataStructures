#include <iostream>
using namespace std;

class PriorityQueue{
public:
    int arr[100],size;
    PriorityQueue(){size=0;}
    void push(int x){
        int i=size++;
        arr[i]=x;
        while(i>0 && arr[(i-1)/2]<arr[i]){
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    int pop(){
        int root=arr[0];
        arr[0]=arr[--size];
        int i=0;
        while(true){
            int l=2*i+1,r=2*i+2,largest=i;
            if(l<size && arr[l]>arr[largest]) largest=l;
            if(r<size && arr[r]>arr[largest]) largest=r;
            if(largest==i) break;
            swap(arr[i],arr[largest]);
            i=largest;
        }
        return root;
    }
    bool empty(){ return size==0; }
};

int main(){
    PriorityQueue pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);
    while(!pq.empty()) cout<<pq.pop()<<" ";
    return 0;
}
