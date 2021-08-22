#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 

string spaceUP(string x, string y, int m, int n){
    int maxlen = 0;         
    int end = m;   
 
    int culture[m + 1][n + 1];
 
    memset(culture, 0, sizeof(culture));
 
    for (int i = 1; i <= m; i++){   
        
        for (int j = 1; j <= n; j++)
        
            
            if (x[i - 1] == y[j - 1])
            {
                culture[i][j] = culture[i - 1][j - 1] + 1;
 
                
                if (culture[i][j] > maxlen)
                
                    maxlen = culture[i][j];
                    end = i;
                
            }
        
    }

    return x.substr(end - maxlen, maxlen);
}
 
int main(){
    
    int t;
    cin>>t;
    while(t--){
        string x,y;
        cin>>x>>y;
        int m = x.size(), n = y.size();
        string ans=spaceUP(x, y, m, n);
        int ok=ans.size();
        int c=(m-ok)+(n-ok);
        cout<<c<<"\n";
    }
    return 0;
}