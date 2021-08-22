/* codeforces exercise solution, link below with the statement.
* https://codeforces.com/problemset/problem/1520/A
*
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	int t,i=0,j=0;
	cin>>t;
	while(t--)
	{
		int p=1;
		map<char,int>m;
		int n;
		cin>>n;
		char a[100];
        while(i< n){
			cin>>a[i];
            i++;
		}
	
        while(j < n)
		{
			if(m[a[j]]!=0&&a[j]!=a[j-1])
			{
				p=0;
				break;
			}	
			
			m[a[j]]++;
            j++;
		}

		if(p==1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
} 
