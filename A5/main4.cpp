#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void resolve(){
    int n;
    cin >> n;
    map<int, int> mp;
    int i=0;
    while(i< n){
        int x;
        cin >> x;
        mp[x]++;
        ++i;
    }

    priority_queue<int> q;
    for (auto i : mp)
    {
        q.push(i.second);
    }

    while (q.size() >= 2)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        a--;
        b--;
        if (a)
            q.push(a);
        if (b)
            q.push(b);
    }

    if (q.size() == 0){
        cout << 0 << "\n";
    }
    else{
        cout << q.top() << "\n";
    }
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
    int i=1;
    while(i<=t){
        
        resolve();
        ++i;
    }
    return 0;
}