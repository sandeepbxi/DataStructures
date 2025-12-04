#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int left=0, right=n-1;
    while(left<right){
        int minIndex=left, maxIndex=right;
        for(int i=left;i<=right;i++){
            if(arr[i]<arr[minIndex]) minIndex=i;
            if(arr[i]>arr[maxIndex]) maxIndex=i;
        }
        swap(arr[left],arr[minIndex]);
        if(maxIndex==left) maxIndex=minIndex;
        swap(arr[right],arr[maxIndex]);
        left++;
        right--;
    }
}

int main(){
    int arr[]={64,25,12,22,11,90,5};
    int n=7;
    improvedSelectionSort(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
