#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	
	while(t--){
		
		int n,k;
		cin >> n >> k;
		
		vector<int> num(n+1);
		
		for(int i = 1;i<=n;i++) cin >> num[i];
		
		long long ans = -1e12;
		int l = max(1,n - 2 * k);
		
		for(int i = l;i<=n;i++)
			for(int j = i+1;j<=n;j++){
				
				ans = max(ans, 1LL * i * j - 1LL * k*(num[i]|num[j]));
			}
			
		cout << ans << endl;
	}
	
	return 0;
}