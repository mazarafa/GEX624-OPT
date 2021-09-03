#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define LONG_MAX_VALUE 0x7fffffffffffffffL
#define LONG_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Resolution
{
    void run()
    {
        int n;
        cin >> n;
        char s[n + 1]{0};
 
        if (n < 10)
        {
            for (int i = 0; i < n; i++)
            {
                s[i] = (char)('a' + i);
            }
            cout << s << endl;
            return;
        }
 
        if (n % 2 == 0)
        {
            int x = (n - 2) / 2;
            for (int i = 0; i < x; i++)
            {
                s[i] = 'a';
            }
            s[x] = 'b';
            for (int i = x + 1; i < n; i++)
            {
                s[i] = 'a';
            }
            cout << s << endl;
        }
        else
        {
            int x = (n - 3) / 2;
            for (int i = 0; i < x; i++)
            {
                s[i] = 'a';
            }
            s[x] = 'b';
            s[x + 1] = 'c';
            for (int i = x + 2; i < n; i++)
            {
                s[i] = 'a';
            }
            cout << s << endl;
        }
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