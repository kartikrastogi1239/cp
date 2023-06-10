#include <iostream>
using namespace std;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int prr[n+1]={0};
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        prr[l]+=1;
        if(r!=n)
            prr[r+1]-=1;
        
    }
    for(int i=1;i<=n;i++){
        prr[i]+=prr[i-1];
    }
    for(int i=1;i<=n;i++){
        cout<<prr[i]<<" ";
    }
    int A[n+1]={0};
    for(int i=1;i<=n;i++){
        if(prr[i]>=k){
            A[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        A[i]+=A[i-1];
    }
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<(A[R]-A[L-1])<<endl;
    }
    return 0;
}