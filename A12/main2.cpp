#include <bits/stdc++.h> 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Resolution{
    
    void run(){
        int n;
        string s;
        cin >> n >> s;
        int first = -1;
        for (int i = 0; i < n; i++){
            if (s[i] != '?')
            {
                first = i;
                break;
            }
        }
 
        if (first == -1){
            for (int i = 0; i < n; i++)
            {
                s[i] = i % 2 == 0 ? 'B' : 'R';
            }
        
        }else{

            for (int i = first; i < n - 1; i++){
                if (s[i + 1] == '?'){
                    s[i + 1] = s[i] == 'B' ? 'R' : 'B';
                }
            }

            first--;
            while (first >= 0){
                s[first] = s[first + 1] == 'B' ? 'R' : 'B';
                first--;
            }
        }
 
        cout << s << endl;
    }
};
 
int main(){

    ios_base::sync_with_stdio(false);
 
    Resolution resolution = Resolution();
 
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        resolution.run();
    }

    return 0;
}