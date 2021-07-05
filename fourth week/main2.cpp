#include <iostream>
#include <cstring>
#include <cmath> 

using namespace std;

const int N = 30010;

int a[N] , c[3];
int t , n;

bool confere(){
	int t = c[0];
	if(c[1] != c[2] || t != c[1]) return false;
	return true;
}

void resolve(){
	cin >> n;
	memset(c , 0 , sizeof c);
	
    for(int i = 0; i < n; i ++) scanf("%d" , &a[i]);
	
    for(int i = 0; i < n; i ++){
		if(a[i] % 3 == 0) c[0] ++;
		else if(a[i] % 3 == 1) c[1] ++;
		else c[2] ++;
	}

	int res = 0;
	int pull = (c[0] + c[1] + c[2]) / 3;
	int i = 0;

	while(!confere())
	{
		while(c[i] > pull)
		{
			c[i] -= 1;
			c[(i + 1) % 3] += 1;
			res += 1;
		}
		i = (i + 1) % 3;
	}
	cout << res << endl;
}

int main(){

	cin >> t;
	while(t --) resolve();
	return 0;
}
