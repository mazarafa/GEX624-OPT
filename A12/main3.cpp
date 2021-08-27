#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Resolution{
    
    void run(){
        int n;
        cin >> n;
        set<int> to_last, to_node;
        for (int i = 1; i <= n; i++)
        {
            int now;
            cin >> now;
            if (now == 0)
            {
                to_last.insert(i);
            }
            else
            {
                to_node.insert(i);
            }
        }
        if (to_last.find(n) != to_last.end())
        {
            for (int i = 1; i <= n + 1; i++)
            {
                cout << i << " ";
            }
        }
        else if (to_node.find(1) != to_node.end())
        {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
        }
        else
        {
            int pos = -1;
            for (int i = 1; i <= n - 1; i++)
            {
                if (to_last.find(i) != to_last.end() && to_node.find(i + 1) != to_node.end())
                {
                    pos = i;
                    break;
                }
            }
 
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
                if (pos == i)
                {
                    cout << n + 1 << " ";
                }
            }
        }
        cout << endl;
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