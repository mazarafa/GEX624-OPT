#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;

int ans[maxn];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	for(int i=0;i<3e5+7;i++){
		    ans[i]=ans[i-1]^i;
		}
	int t;
	cin>>t;
	while(t--){
	    
		int n,m;
		cin>>n>>m;
		
		if(ans[n-1]==m)cout<<n<<endl;
		else if((ans[n-1]^m)==n)cout<<n+2<<endl;
		else cout<<n+1<<endl;
	}

}