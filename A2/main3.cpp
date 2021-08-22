/**
 *      https://codeforces.com/contest/1538/problem/C
 * 
 * */

#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ans,up,num,s,i,l,r;
    cin>>up;
    
    while(up--){
        cin>>num>>l>>r;
        vector<long long>value(num);

        i = 0 ;
        while(i<num){
            cin>>value[i];
            i++;
        }

        
        sort(value.begin(),value.end());
        ans=0;

        for(i=0;i<num-1;i++){
             auto itr1=lower_bound(value.begin()+i+1,value.end(),l-value[i]);
             auto itr2=upper_bound(value.begin()+i+1,value.end(),r-value[i]);
             ans+=(itr2-itr1);
        }
        cout<<ans<<"\n";
    }
}