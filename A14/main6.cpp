#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200010;
const int INF = 1000000007;

int n, q;
int a[maxn], p[maxn];

struct Node{
	int mi, tag;
	ll sum;
}t[maxn<<2];

void pushup(int i){
	t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
	t[i].mi = min(t[i<<1].mi, t[i<<1|1].mi);
}

void build(int i, int l, int r){
	t[i].tag = 0;
	if(l == r){
		t[i].mi = t[i].sum = p[l];
		return;
	}
	
	int mid = (l + r) >> 1;
	build(i<<1, l, mid); build(i<<1|1, mid+1, r); 
	pushup(i);
}

void pushdown(int i, int l, int r){
	if(t[i].tag){
		t[i<<1].tag = t[i<<1|1].tag = t[i].tag;
		t[i<<1].mi = t[i<<1|1].mi = t[i].tag;
		
		int mid = (l + r) >> 1;
		t[i<<1].sum = 1ll * (mid-l+1) * t[i].tag;
		t[i<<1|1].sum = 1ll * (r-mid) * t[i].tag;
		
		t[i].tag = 0;
	}
}

void modify(int i, int k, int l, int r, int x, int y){
	if(x <= l && r <= y){
		t[i].tag = k;
		t[i].sum = 1ll * (r-l+1) * k;
		t[i].mi = k;
		return;
	} 
	pushdown(i, l, r);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(i<<1, k, l, mid, x, y);
	if(y > mid) modify(i<<1|1, k, mid+1, r, x, y);
	pushup(i);
}

ll qsum(int i, int l, int r, int x, int y){
	if(x <= l && r <= y) {
		return t[i].sum;
	}
	pushdown(i, l, r);
	
	int mid = (l + r) >> 1;
	ll res = 0;
	if(x <= mid) res += qsum(i<<1, l, mid, x, y);
	if(y > mid) res += qsum(i<<1|1, mid+1, r, x, y);
	return res;
}

int find(int i, int v, int p, int l, int r){
	if(l > r) return 0;
	if(l == r) return l;
	pushdown(i, l, r);
	int mid = (l + r) >> 1;
	
	int pos = -1;
	if(t[i<<1|1].mi <= v) pos = find(i<<1|1, v, p, mid+1, r);
	if(pos != -1) return pos;
	if(t[i<<1].mi <= v && p <= mid) pos = find(i<<1, v, p, l, mid);
	return pos;
}

int findl(int i, int v, int x, int y, int l, int r){
	if(l == r) return l;
	pushdown(i, l, r);
	int mid = (l + r) >> 1;
	
	int pos = -1;
	if(t[i<<1|1].mi < v && y > mid) pos = findl(i<<1|1, v, x, y, mid+1, r);
	if(pos != -1) return pos;
	if(t[i<<1].mi < v && x <= mid) pos = findl(i<<1, v, x, y, l, mid);
	return pos;
}

ll read(){ ll s = 0, f = 1; char ch = getchar(); while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); } while(ch >= '0' && ch <= '9'){ s = s * 10 + ch - '0'; ch = getchar(); } return s * f; }

int main(){
	n = read(), q = read();
	for(int i = 1 ; i <= n ; ++i) a[i] = read();
	a[0] = INF;
	a[n+1] = INF;
	
	p[1] = 1;
	for(int i = 2 ; i <= n ; ++i) {
		if(a[i] >= a[i-1]) p[i] = p[i-1];
		else p[i] = i;
	}

	build(1, 1, n);

	int op, l, r; 
	for(int i = 1 ; i <= q ; ++i){
		op = read(), l = read(), r = read();
		if(op == 1){
			a[l] = r;
			int tmp = qsum(1, 1, n, l, l);
			if(a[l] >= a[l-1]){
				int pp = qsum(1, 1, n, l-1, l-1); 
				modify(1, pp, 1, n, l, l);
			}
			else {
				modify(1, l, 1, n, l, l);
			}
			
			if(a[l] > a[l+1]) {
				int pos = find(1, tmp, l+1, 1, n);
				if(pos != -1){
					modify(1, l+1, 1, n, l+1, pos);
				}
			} else{
				int ps = qsum(1, 1, n, l+1, l+1);
				int pos = find(1, ps, l+1, 1, n);
				if(pos != -1){
					int pp = qsum(1, 1, n, l, l);
					modify(1, pp, 1, n, l+1, pos); 
				} 
			}
		} else{
			int pos = findl(1, l, l, r, 1, n);
			ll res = 1ll * (r - l + 1);
			if(pos != -1) res -= 1ll * l * (pos-l+1);
			res += 1ll * (l+r) * (r-l+1) / 2;
			res -= qsum(1, 1, n, (pos==-1)?l:pos+1, r);
			printf("%lld\n", res);
		}
	}
	
	return 0;
}