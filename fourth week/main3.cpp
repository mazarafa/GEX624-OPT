#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;
#define helpers long long
map<helpers, helpers> mp;

int main(){

    helpers i = 1;
    while(i <= 10000){
  
        mp[i * i * i] = 1;

        i++;
    }

    int t;
    cin >> t;
    while (t--){
        helpers n;
        cin >> n;
        int flag = 0;
        for (helpers i = 1; i <= 10000; i++){
            if (mp[n - i * i * i] == 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}