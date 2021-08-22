/*
    https://codeforces.com/problemset/problem/1512/B
*/
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
 
string s[410];
 
int main() 
{
	int t; 
	cin >> t;
	while (t--) 
	{
		int i,n; 
        cin >> n;
        i = 0;
        while(i<n)
		
		{
			cin >> s[i];
            ++i;
		}
		
        int x1, y1, x2, y2,j, flag = 0;
		
        for (int i = 0; i < n; i++)
		{
            j = 0;
			while(j< n)
           
			{
				if (s[i][j] == '*') 
				{
					if (flag == 0)
					{
						x1 = i;
						y1 = j;
						flag = 1;
					}
					else
					{
						x2 = i;
						y2 = j;
					}
				}
                ++j;
			}
		}
		if (x1 == x2) 
		{
			if (x1 == 0)
			{
				x1 = x2 = 1;
			}
			else
			{
				x1 = x2 = 0;
			}
		}
		else if (y1 == y2) 
		{
			if (y1 == 0)
			{
				y1 = y2 = 1;
			}
			else
			{
				y1 = y2 = 0;
			}
		}
		s[x1][y2] = '*'; 
		s[x2][y1] = '*';
		
        for (int i = 0; i < n; i++)
		{
			cout << s[i] << '\n';
		}
	}
	return 0;
}