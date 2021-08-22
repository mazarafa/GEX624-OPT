/**
 *  https://codeforces.com/problemset/problem/1538/B
 * 
 * 
 * 
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

void SotrackBoa(){
    int num;
    cin>>num;
    int value[num];
    int up=0;

    int i=0;
    while(i<num) {
        cin>>value[i];
        up+=value[i];
        ++i;
    }
   
    if(up%num!=0){
        cout<<-1<<"\n";
        return ;
    }
    
    up=up/num; 
    
    int ans=0; 
    for(int i=0;i<num;i++){
        if(value[i]>up) 
            ans++; 
    }
    cout<<ans<<"\n";
    
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        SotrackBoa();
    }
    return 0;
}