#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7, md = 998244353;
int n, m, l[maxn], r[maxn], mu[maxn], tot, pri[maxn];
bool isp[maxn];
int ans;
void sieve() {
	memset(isp, true, sizeof(isp));
	isp[1] = false;
	mu[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		if (isp[i]) {
			pri[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * pri[j] <= 100000; j++) {
			isp[i * pri[j]] = false;
			if (i % pri[j] == 0) {
				mu[i * pri[j]] = 0;
				break;
			}
			mu[i * pri[j]] = -mu[i];
		}
	}
}

int f[51][maxn], sum[51][maxn];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	sieve(); 
	for (int d = 1; d <= m; d++) {
		if (mu[d] == 0) continue;
		int cur = m / d;
		for (int i = 0; i <= cur; i++) 
			sum[0][i] = 1;
		for (int i = 1; i <= n; i++) {
			int L = (l[i]-1)/d+1, R = r[i]/d;
			for (int j = L; j <= cur; j++) {
				f[i][j] = sum[i-1][j-L];
				if (j >= R+1)
					f[i][j] = (f[i][j] - sum[i-1][j-R-1] + md) % md;
			}
			for (int j = 1; j <= cur; j++)
				sum[i][j] = (sum[i][j-1] + f[i][j])%md;
		}
		ans = (ans + sum[n][cur] * mu[d]) % md;
		if (ans < 0)
			ans = (ans + md) % md;
	}
	printf("%d", ans);
}