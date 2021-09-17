#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int a[maxn];
ll fact[maxn];
ll infact[maxn];
const int mod = 998244353;
typedef pair <int, int> PII;
int ksm(int base, int power, int mod)
{
    int res = 1;
    while(power)
    {
        if(power & 1)
        res = (ll)res * base % mod;
        base = (ll)base * base % mod;
        power >>= 1;
    }
    return res;
}
int main()
{   
    int T;
    scanf("%d", &T);
    fact[0] = infact[0] = 1;
    for(int i = 1 ; i <= 200000 ; i ++)
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * ksm(i, mod - 2, mod) % mod;
    }   
    while(T --)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1 ; i <= n ; i ++)
        scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        bool flog = false;  
        int cnt1 = count(a + 1, a + n + 1, a[n]);
        int cnt0 = count(a + 1, a + n + 1, a[n - 1]);
        if(a[n] - a[n - 1] == 1 || a[n] - a[n - 1] == 0)
        flog = true;
        if(!flog)
        printf("0\n");
        else if(cnt1 == 1)
        {
            ll sum = 0;
            int temp = n - cnt1 - cnt0;
            for(int i = cnt0 + 1 ; i <= n ; i ++)
            {
                sum += (fact[temp] % mod * (infact[temp - (n - i)] % mod)) %mod * fact[i - 1] % mod;         
                sum %= mod;         
            }
            printf("%lld\n", (fact[n] - sum + mod) % mod);
        }
        else if(cnt1 > 1)
        printf("%lld\n", fact[n]);
    } 
    return 0;
}

