#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int a[maxn];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;  cin>>T;
	while(T--){
		int n;  cin>>n;
		for(int i = 1; i <= n; i++)cin>>a[i];
		sort(a+1,a+n+1);
		double ans = 0;
		for(int i = 1; i < n; i++){
			ans += a[i];
		}
		ans /= (n-1);
		ans += a[n];
		printf("%.10lf\n", ans);
	}
	return 0;
}
