/**
 *  https://codeforces.com/contest/1538/problem/F
*/
#include<bits/stdc++.h>  
#define helperUp long long 
using namespace std;
 
helperUp soTrackBoa(helperUp n){

    helperUp up=0;
    while(n!=0){
        up+=n;
        n=n/10;
    }

    return up;
}
 
int main(){
    
    helperUp num;
    cin>>num;
    
    while(num--){
        helperUp x,y,pull,pulls;
        cin>>x>>y;
        pull=soTrackBoa(x);
        pulls=soTrackBoa(y);
        cout<<pulls-pull<<endl;
    }
    return 0;
}