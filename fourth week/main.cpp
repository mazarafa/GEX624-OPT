#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,l=0;
		float z,x,m;
		cin>>n;
		int a[n];
		
        int i=0;
        while(i<n){
       
			cin>>a[i];
            i++;
		}

		for(int i=0;i<n;i++){	
			int j=i+1;

			if(j<n)
			{
				x=max(a[i],a[j]);
				m=min(a[i],a[j]);
				z=x/m;
				
                while(z>2)
				{
					m=m*2;
					z=x/m;
					l++;
				}
			}
		}

		cout<<l<<"\n";
	}
}



