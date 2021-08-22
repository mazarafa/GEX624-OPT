#include<stdio.h>
 
int main()
{
	int t;
	long long int n, c2, c1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld", &n);
		c2 = (n + 1) / 3;
		c1 = n - (2 * c2);
		printf("%lld %lld\n", c1, c2);
	}
	return 0;
}
