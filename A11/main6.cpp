#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn = 1e6 + 7;
set<ll > s1, s2;
void pre() {
	for (ll i = 0; i <= 9; ++i) {
		ll num = 0;
		for (ll j = 1; j <= 10; ++j) {
			num = num * 10 + i;
			s1.insert(num);
			s2.insert(num);
		}
	}
	for (ll i = 0; i <= 9; ++i){
		for (ll j = i + 1; j <= 9; ++j){
			for (int k = 0; k < (1 << 10); ++k){
				ll num = 0;
				for (int l = 0; l <= 9; ++l){
					if ((k >> l) & 1)num = num * 10 + i;
					else num = num * 10 + j;
					s2.insert(num);
				}

			}
		}

	}
}

int main() {
	pre();
	int T;
	scanf("%d", &T);
	while (T--) {
		ll n;
		int  k;
		scanf("%lld %d", &n, &k);
		if (k == 1)printf("%lld\n", *s1.lower_bound(n));
		else printf("%lld\n",*s2.lower_bound(n));
	}
}