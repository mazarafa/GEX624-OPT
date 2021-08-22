#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2E5 + 10, M = 20;
LL a[N], b[N];
int n;
LL f[N][M];
int l2g[N];

void init() {
    for (int j = 0; j < M; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if (!j) f[i][j] = b[i];
            else f[i][j] = __gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
}

LL query(int l, int r) {
    int k = l2g[r - l + 1];
    return __gcd(f[l][k], f[r - (1 << k) + 1][k]);
}

int main() {
    int t; scanf("%d", &t);
    l2g[2] = 1;
    for (int i = 3; i <= N; i++) l2g[i] = l2g[i / 2] + 1;
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n - 1; i++) b[i] = abs(a[i] - a[i + 1]);
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        init();
        
        int res = 0;
        int j = 1;
        for (int i = 1; i <= n - 1; i++) {
            while (j <= i && query(j, i) == 1) j++;
            res = max(res, i - j + 2);
        }

        printf("%d\n", res);
    }

    return 0;
} 