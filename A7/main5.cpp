#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,Cnt[4][4];
ll Ans;
ll C2(int S){   return 1ll*S*(S-1)/2;   }
ll C3(int S){   return 1ll*S*(S-1)*(S-2)/6;   }
int main()
{   scanf("%d",&n);
    for(int i=1,X,Y;i<=n;i++) scanf("%d%d",&X,&Y),Cnt[X%4][Y%4]++;
    Ans=C3(Cnt[0][0])+C3(Cnt[0][2])+C3(Cnt[2][0])+C3(Cnt[2][2]);
    Ans+=C2(Cnt[0][0])*(n-Cnt[0][0])+C2(Cnt[0][2])*(n-Cnt[0][2])+C2(Cnt[2][0])*(n-Cnt[2][0])+C2(Cnt[2][2])*(n-Cnt[2][2]);
    printf("%lld\n",Ans);
}