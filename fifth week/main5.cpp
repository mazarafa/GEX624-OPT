#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define str string
#define pb push_back
#define vc vector
#define ci cin
#define co cout
#define mod 1000000007
 
int main()
{ 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	ll mn[n+1],mx[n+1],vis[n+1],a[n+1];
    	
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i];
    		vis[i]=0;
    		mx[i]=-1;
    		mn[i]=-1;
    		
    	}
    	mn[1]=a[1],mx[1]=a[1];
    	vis[a[1]]=1;
    	for(int i=2;i<=n;i++)
    	{
    		if(a[i]>a[i-1])
    		{
    			mn[i]=a[i];
    			mx[i]=a[i];
    			vis[a[i]]=1;
    			
    		}
    	}
    	vector<ll>v;
    	for(int i=1;i<=n;i++)
    	{
    		if(!vis[i])
    		v.pb(i);
    	}
    	sort(v.begin(),v.end());
    	set<ll>st;
    	for(auto u:v)
    	st.insert(u);
    	ll ix=0;
    	for( int i=1;i<=n;i++)
    	{
    		if(mn[i]==-1)
    		{
    			mn[i]=v[ix];
    			
    			ix++;
    		}
    		cout<<mn[i]<<" ";
    	}
    	cout<<"\n";
    	ix=v.size()-1;
    	ll p[n+1];ll val=-1;
    	
    	for(int i=1;i<=n;i++)
    	{
    		if(mx[i]==-1)
    		{
    			auto u=st.lower_bound(a[i]);
    			u--;
    			
    		    mx[i]=(*u);
    		    st.erase(*u);
    		}
    		
    	}
    	for(int i=1;i<=n;i++)
    	cout<<mx[i]<<" ";
    	cout<<"\n";
    }
    
    
}