#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Node
{
    int value, pos;
};
 
struct Resolution
{
    void run()
    {
        int n;
        cin >> n;
        Node a[n];
        Node b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].value;
            a[i].pos = i;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i].value;
            b[i].pos = i;
        }
        sort(a, a + n, [](const Node &o1, const Node &o2) -> bool
             { return o1.value < o2.value; });
 
        sort(b, b + n, [](const Node &o1, const Node &o2) -> bool
             { return o1.value < o2.value; });
 
        int ans = Integer_MAX_VALUE;
        int d_a = Integer_MAX_VALUE;
        for (int i = 0; i < n; i++)
        {
            d_a = min(d_a, a[i].pos);
            int d_b = b[i].pos;
            ans = min(ans, d_a + d_b);
        }
        cout << ans << endl;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    Resolution resolution = Resolution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        resolution.run();
    }
    return 0;
}