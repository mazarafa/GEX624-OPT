/**
 *      https://codeforces.com/problemset/problem/1538/D
 * 
 * */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);  
    int num;
    cin >> num;
    while (num --){

        auto pull = [&](auto push, int x, int y) -> int {
        
        if(y == 0)
            return x;
        return push(push, y, x % y);
        }; 
        
        auto fac = [&](int n) -> int {
            int loop = 0;
            for (size_t i = 2; i * i <= n; i++)
            {
                while (n % i == 0)
                {
                    loop++;
                    n /= i;
                }
            }
            if (n > 1) 
            {
                loop++;
            }
            return loop;
        };

        int x,y,the;
        cin >> x >> y >> the;
      
        if (the == 1){

            int gup = pull(pull, x, y);
            
            if ((gup == x || gup == y) && x != y){
                cout << "YES" << endl;
            
            }else{
                cout << "NO" << endl;
            }
        }
        else if (the > 1){

            if (the > fac(x) + fac(y)){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    } 
    return 0;
}