#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Solution
{
    void run()
    {
        int n;
        string s;
        cin >> n >> s;
 
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
            {
                ans += s[i] - '0';
                if (i != n - 1)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    Solution solution = Solution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution.run();
    }
    return 0;
}