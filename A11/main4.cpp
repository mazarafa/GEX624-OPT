#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> v;


string multiplyS(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";

    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

ll Help(string a, string b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    ll count = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
            i++;
        else
            count++;

        j++;
    }

    count += (n - i);
    count += (m - j);
    return count;
}

void solve(ll k)
{
    string r = to_string(k);
    ll ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        ll curr = Help(v[i], r);
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    v.clear();
    string pre = "1";
    string mul = "2";
    v.push_back(pre);
    for (ll j = 0; j <= 500; j++)
    {
        string s = multiplyS(pre, mul);
        v.push_back(s);
        pre = s;
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}

// references https://www.youtube.com/watch?v=6ywjZpUcmWc