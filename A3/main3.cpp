/*
* https://codeforces.com/problemset/problem/1512/C
*/
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int len = a + b;
        
        for (int i = 0; i < len; i++)
    
            if (s[i] == '?')
            s[i] = s[len - i - 1];

        a -= count(s.begin(), s.end(), '0');
        b -= count(s.begin(), s.end(), '1');
        for (int i = 0; i <= len / 2; i++)
        {
            if (i != len - i - 1 && s[i] == '?')
            {
                if (a >1) { s[i] = '0'; s[len - i - 1] = '0'; a -= 2; }
                else if (b >1) { s[i] = '1'; s[len - i - 1] = '1'; b -= 2; }
            }

            else if(s[i]=='?')
            {
                if (a>0) {
                    s[i] = '0'; a--;
                }
                else if (b > 0)
                {
                    s[i] = '1'; b--;
                }
            }
        }

        string v = s;
        reverse(v.begin(), v.end());

        if (v == s&&a==0&&b==0){
            cout << s << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
