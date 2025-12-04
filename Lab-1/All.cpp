#include <iostream>
using namespace std;

void menuDrivenArray() {
    int arr[100], n=0, choice, pos, val, i;
    while(true) {
        cout << "\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin >> choice;
        if(choice==1) {
            cout << "Enter size: "; cin >> n;
            for(i=0;i<n;i++) cin >> arr[i];
        } else if(choice==2) {
            for(i=0;i<n;i++) cout << arr[i] << " ";
            cout << endl;
        } else if(choice==3) {
            cout << "Enter position and value: "; cin >> pos >> val;
            for(i=n;i>pos;i--) arr[i]=arr[i-1];
            arr[pos]=val; n++;
        } else if(choice==4) {
            cout << "Enter position: "; cin >> pos;
            for(i=pos;i<n-1;i++) arr[i]=arr[i+1];
            n--;
        } else if(choice==5) {
            cout << "Enter value: "; cin >> val;
            for(i=0;i<n;i++) if(arr[i]==val) { cout << "Found at " << i << endl; break; }
            if(i==n) cout << "Not Found\n";
        } else break;
    }
}

void removeDuplicates() {
    int n; cin >> n;
    int arr[100];
    for(int i=0;i<n;i++) cin >> arr[i];
    int k=0;
    for(int i=0;i<n;i++) {
        bool found=false;
        for(int j=0;j<k;j++) if(arr[i]==arr[j]) {found=true; break;}
        if(!found) arr[k++]=arr[i];
    }
    for(int i=0;i<k;i++) cout << arr[i] << " ";
    cout << endl;
}

void predictOutput() {
    int i; int arr[5] = {1};
    for (i=0;i<5;i++) cout << arr[i];
    cout << endl;
}

void reverseArray() {
    int n; cin >> n;
    int arr[100];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n/2;i++) swap(arr[i],arr[n-1-i]);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}

void matrixMultiplication() {
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(c1!=r2) { cout << "Not Possible\n"; return; }
    int A[10][10],B[10][10],C[10][10]={0};
    for(int i=0;i<r1;i++) for(int j=0;j<c1;j++) cin >> A[i][j];
    for(int i=0;i<r2;i++) for(int j=0;j<c2;j++) cin >> B[i][j];
    for(int i=0;i<r1;i++) for(int j=0;j<c2;j++) for(int k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
    for(int i=0;i<r1;i++){ for(int j=0;j<c2;j++) cout << C[i][j] << " "; cout << endl; }
}

void transposeMatrix() {
    int r,c; cin >> r >> c;
    int A[10][10];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> A[i][j];
    for(int i=0;i<c;i++){ for(int j=0;j<r;j++) cout << A[j][i] << " "; cout << endl; }
}

void sumRowsCols() {
    int r,c; cin >> r >> c;
    int A[10][10];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> A[i][j];
    for(int i=0;i<r;i++){ int sum=0; for(int j=0;j<c;j++) sum+=A[i][j]; cout << "Row " << i << " sum=" << sum << endl; }
    for(int j=0;j<c;j++){ int sum=0; for(int i=0;i<r;i++) sum+=A[i][j]; cout << "Col " << j << " sum=" << sum << endl; }
}

int main() {
    cout << "Menu Driven Array:\n"; menuDrivenArray();
    cout << "Remove Duplicates:\n"; removeDuplicates();
    cout << "Predict Output:\n"; predictOutput();
    cout << "Reverse Array:\n"; reverseArray();
    cout << "Matrix Multiplication:\n"; matrixMultiplication();
    cout << "Transpose:\n"; transposeMatrix();
    cout << "Sum of Rows and Cols:\n"; sumRowsCols();
    return 0;
}
