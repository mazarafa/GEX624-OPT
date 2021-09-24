#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Solution
{
    int n, *a;
    vector<int> *ans;
 
    void run()
    {
        cin >> n;
        a = new int[n];
 
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                count++;
        }
 
        if (count % 2 == 1)
        {
            cout << "NO" << endl;
            return;
        }
 
        bool flag = true;
        ans = new vector<int>();
        if (check(0, 1))
        {
            for (int i = 0; i <= n - 3; i++)
            {
                check(i, 1);
            }
        }
        else if (check(n - 1, -1))
        {
            for (int i = n - 1; i >= 2; i--)
            {
                check(i, -1);
            }
        }
        else if (!build_zero(0, 1) && !build_zero(n - 3, -1))
        {
            flag = false;
        }
 
        if (flag)
        {
            cout << "YES" << endl;
            cout << ans->size() << endl;
            for (int now : *ans)
            {
                cout << now + 1 << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
 
    bool build_zero(int start, int d)
    {
        int backup[n];
        for (int i = 0; i < n; i++)
        {
            backup[i] = a[i];
        }
        int i = start - 2 * d;
        do
        {
            i += 2 * d;
            apply(i);
        } while (a[i] == 1 && i + 2 * d <= n - 3 && i + 2 * d >= 2);
        if (a[i] == 0)
        {
            for (int j = i; j >= 2; j--)
            {
                check(j, -1);
            }
            for (int j = i; j <= n - 3; j++)
            {
                check(j, 1);
            }
            return true;
        }
        else
        {
            ans->clear();
            for (int i = 0; i < n; i++)
            {
                a[i] = backup[i];
            }
            return false;
        }
    }
 
    bool check(int start, int d)
    {
        int target = min(start, start + 2 * d);
 
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (a[start + i * d] == 1)
            {
                count++;
            }
        }
 
        if (count == 3)
            return false;
        if (count == 0)
            return true;
        if (count == 2)
        {
            apply(target);
            return true;
        }
 
        //        assert count == 1;
        if (a[start] == 1)
        {
            return false;
        }
        else if (a[start + d] == 0)
        {
            return true;
        }
        else
        {
            apply(d == 1 ? start + d : start + d - 2);
            if (a[start + d] == 1)
            {
                apply(target);
            }
            return true;
        }
    }
 
    void apply(int target)
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (a[target + i] == 1)
            {
                count++;
            }
        }
        if (count == 0)
            return;
 
        ans->push_back(target);
        for (int i = 0; i < 3; i++)
        {
            a[target + i] = count % 2;
        }
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