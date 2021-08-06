#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
string str1, str2;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int cnt = 0;
        vector<int> v1;
        int n;
        cin >> n;
        cin >> str1;
        cin >> str2;
        for (int i = 0; i < n; i++)
            if (str2[i] == '1') v1.push_back(i);
        for (int i = 0; i < v1.size(); i++) {
            
            if (str1[v1[i]] == '0') cnt++;
            else if (v1[i] == 0) {
                if (str1[v1[i] + 1] == '1') cnt++, str1[v1[i] + 1] = '2';
            } else if ((str1[v1[i] - 1] == '1') || str1[v1[i] + 1] == '1') {
                cnt++;
                if (str1[v1[i] - 1] == '1') {
                    str1[v1[i] - 1] = '2';
                } else {
                    str1[v1[i] + 1] = '2';
                }

            }

        }
        cout << cnt << endl;
    }

}
