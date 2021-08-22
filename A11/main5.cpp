#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
int T;
const int N = 30;
int visit[30];
int main()
{
    cin>>T;
    while(T--)
    {
        memset(visit,0,sizeof visit);
        string s,new_s;
        int len = 0,flag = 0;
        cin>>s;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++)
        {
            if(!visit[s[i]-'a'])
            new_s.push_back(s[i]);
            visit[s[i]-'a']++;
        }
        int length = new_s.size();
        for(int i=0;i<new_s.size();i++)
        {
            int temp = visit[new_s[i]-'a']%(length-i);
            if(temp!=0)
            {
                flag=1;
                cout<<-1<<endl;
                break;
            }
            len+=visit[new_s[i]-'a']/(length-i);
        }
        if(!flag)
        {
            reverse(s.begin(),s.end());
            reverse(new_s.begin(),new_s.end());
            string res;
            for(int i=0;i<len;i++)
            res.push_back(s[i]);

            string ans(res);
            string ans1(res);
            for(int i=0;i<new_s.size();i++)
            {
                ans.erase(remove(ans.begin(),ans.end(),new_s[i]),ans.end());
                ans1 += ans;
            }
            if(ans1 == s)
            cout<<res<<" "<<new_s<<endl;
            else
            cout<<-1<<endl;
        }
    }
    return 0;
}

