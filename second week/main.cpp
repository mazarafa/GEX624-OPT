#include <bits/stdc++.h>

using namespace std;
void solve(int ar[],int n){
    int mini=INT_MAX,idx1=0,maxi=INT_MIN,idx2=0;
    for(int i=0;i<n;i++){
        if(ar[i]<mini){
            idx1=i;
            mini=ar[i];
        }
        if(ar[i]>maxi){
            idx2=i;
            maxi=ar[i];
        }
    }
    int flag1=0,flag2=0,ans1=0,ans2=0,ans3=0,cnt=1;
    for(int i=0;i<n;i++){
        if(idx1==i){
            flag1=1;
        }
        if(idx2==i){
            flag2=1;
        }
        if(flag1&&flag2){
            break;
        }
        cnt++;
    }
    ans1=cnt;
    cnt=1;flag1=0,flag2=0;
    for(int i=n-1;i>=0;i--){
        if(idx1==i){
            flag1=1;
        }
        if(idx2==i){
            flag2=1;
        }
        if(flag1&&flag2){
            break;
        }
        cnt++;
    }
    ans2=cnt;
    if(idx1<idx2){
        ans3=(idx1+1-0)+(n-idx2);
    }
    else{
        ans3=(idx2+1-0)+(n-idx1);
    }
    //cout<<ans1<<"  "<<ans2<<"  "<<ans3<<"\n";
    cout<<min(ans1,min(ans2,ans3))<<"\n";
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int ar[n]={0};
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        if(n==2){
            cout<<"2"<<"\n";
            continue;
        }
        else{
            solve(ar,n);
        }
    }
    return 0;
}