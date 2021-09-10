#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1e5+5;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();

        int a=0,b=0;

        for(int i=0;i<n;i++){
            if(i&1){
                a*=10;
                a+=s[i]-'0';
            }
            else {
                b*=10;
                b+=s[i]-'0';
            }
        }

        cout<<(a+1)*(b+1)-2<<endl;
    }

}