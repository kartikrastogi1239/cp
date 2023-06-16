#include <bits/stdc++.h>
using namespace std;
int arr[11][11]={0};
bool isPossible(int n,int row, int col){
    for(int i=row-1;i>=0;i--){
        if(arr[i][col]==1)
            return false;
    }
    
    for(int i=row-1,j=col-1;j>=0,i>=0;j--,i--){
        if(arr[i][j]==1)
            return false;
    }
    for(int i=row-1,j=col+1;i>=0,j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    return true;
}

void nQuennHelper(int n,int row){
    if(row==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"_____________"<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(isPossible(n,row,i)){
            arr[row][i]=1;
            nQuennHelper(n,row+1);
            arr[row][i]=0;
        }
    }
    return;
    
    
}

void placeNqueen(int n){
    nQuennHelper(n,0);
    return;
}
int main(){
    int n;
    cin>>n;
    placeNqueen(n);
    return 0;
}
