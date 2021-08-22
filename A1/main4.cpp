#include <iostream>
#include <bits/stdc++.h>
#define helpD long long

using namespace std;
 
const int M = 1e9+7;

helpD mod(helpD x){
    return (x%M + M)%M;
}
 
helpD mul(helpD a, helpD b){
    return mod((mod(a)*mod(b)));
}
 
helpD add(helpD a , helpD b){
    return mod(mod(a)+mod(b));
}
  
void solve(){
    int n;
    cin>>n;
    map<helpD,helpD>mp;
    
    int i=0;

    while(i < n){
        helpD x;
        cin>>x;
        mp[x-i]++;
        i++;
    }
    
    helpD total=0;
    
    for(auto i : mp){
       
        total+=(i.second)*(i.second-1)/2;
    }
    
    cout<<total<<"\n";
}  

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
    cout<<setprecision(10);
   
    int t=1;
    cin>>t;
    
    int i = 1;
            
    while(i<=t){
             
        solve();
        i++;
    }
    return 0;
}