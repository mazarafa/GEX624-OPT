#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define LONG_MAX_VALUE 0x7fffffffffffffffL
#define LONG_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Resolution{
    void run()
    {
        int n;
        cin >> n;
        long a[n];
 
        long ans = LONG_MIN_VALUE;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0)
            {
                ans = max(ans, a[i] * a[i - 1]);
            }
        }
        cout << ans << endl;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
 
    Resolution resolution = Resolution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        resolution.run();
    }
    return 0;
}