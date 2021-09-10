#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;

int vis[maxn];

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    for(int i=0;i<n;i++){
	        if(s[i]=='L')cout<<"L";
	        else if(s[i]=='R')cout<<"R";
	        else if(s[i]=='U')cout<<"D";
	        else cout<<"U";
	    }
	    cout<<endl;
	}

}