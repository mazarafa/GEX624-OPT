#include <iostream>
#include <bits/stdc++.h>
#define llop long long
using namespace std;

void push()
{
    llop n, m, x;
    cin >> n >> m >> x;
    llop a = (x - 1) / n;
    llop b = (x - 1) % n;
    llop ans = (b)*m + (a + 1);
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);

    int t = 1;
    cin >> t;
    int i = 1;
    while (i <= t){
        
        push();
        ++i;
    }

    return 0;
}