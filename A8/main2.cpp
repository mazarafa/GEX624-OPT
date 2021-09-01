#include<bits/stdc++.h>
#define maxn 55
typedef long long ll;
using namespace std;
int main()
{
   ll t,i,count[maxn]={0},sum;
   cin>>t;
   while(t--)
   {
       string s;
       sum=0;
       cin>>s;
       for(i=0;i<s.size();i++)
       {
           count[s[i]-'a']++;
           if(count[s[i]-'a']<=2) sum++;
       }
       memset(count,0,sizeof(count));
       printf("%lld\n",sum/2);
   }
   return 0;
}