/* codeforces exercise solution, link below with the statement.
* https://codeforces.com/contest/1520/problem/B
*
*/

#include <iostream>
#include <bits/stdc++.h>
#define helperB long long
using namespace std;
 
const int M = 1e9+7;

helperB mod(helperB x){
  return (x%M + M)%M;
}
 
helperB mul(helperB a, helperB b){
  return mod((mod(a)*mod(b)));
}
 
helperB add(helperB a , helperB b){
  return mod(mod(a)+mod(b));
}
 
 
void resolvendo(){
  int i = 1;
  helperB n;
  cin>>n;
  helperB total=0;
   
  while(i<=9){ 
    helperB x=0;
    int j = 1;
    while(j<=10){
      x=x*10+i;

      if(x<=n) 
        total++;

      j++;
    }
    i++;

  }
  
  cout<<total<<"\n";
} 

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout<<fixed;
  cout<<setprecision(10);
   
  int t=1, i=1;
  cin>>t;
  while(i<=t){  
    resolvendo();
    i++;
  }
  
  return 0;
}