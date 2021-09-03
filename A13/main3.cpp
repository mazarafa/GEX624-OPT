#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t;
LL n, m;


LL ct(LL x) {
    LL res = 1;
    while(true) {
        if ((x & res) == 0) return res;
        res <<= 1;
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &m);
        if (n > m) {
            printf("0\n");
            continue;
        }

        
        LL tmp = 1, last = -1;
        while(tmp <= n) {
            if ((n & tmp) != 0 && (m & tmp) == 0) {
                last = tmp;
            }
            tmp <<= 1;
        }

        LL p = ct(m);
        if (last == -1) {
            printf("%lld\n", m+p-n-(m%p)+(n%p));
        } else {
            printf("%lld\n", m-(m%last)-(n-(n%last)-last));
        }
    }
}