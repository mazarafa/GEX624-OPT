#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll qmi(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        int t=qmi(2,n-1);
        ll ans=0;
        if(n%2)
        {
            ans=qmi(t+1,k);
        }
        else
        {
               ans=qmi(t-1,k);
               for(int i=1;i<=k;i++)
               {
                   ans=(ans+qmi(t-1,i-1)*qmi(t*2,k-i)%mod)%mod;
               }
        }
        cout<<ans<<endl;
    }
    return 0;
}