#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define Long_MAX_VALUE 0x7fffffffffffffffL
#define Long_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Node{
    int index, depends_count;
    vector<int> next;
};
 
struct Resolution{
    void run()
    {
        int n;
        cin >> n;
        Node nodes[n];
        for (int i = 0; i < n; i++)
        {
            nodes[i].index = i;
        }
 
        queue<int> *current_queue;
        queue<int> *next_queue;
        next_queue = new queue<int>();
        for (int i = 0; i < n; i++)
        {
            cin >> nodes[i].depends_count;
            for (int j = 0; j < nodes[i].depends_count; j++)
            {
                int x;
                cin >> x;
                x--;
                nodes[x].next.push_back(i);
            }
 
            if (nodes[i].depends_count == 0)
            {
                next_queue->push(i);
            }
        }
 
        int ans = 0;
        int remain = n;
        while (remain != 0)
        {
            current_queue = next_queue;
            next_queue = new queue<int>();
 
            if (current_queue->empty())
            {
                cout << -1 << endl;
                return;
            }
 
            ans++;
            set<int> must_next;
            while (!current_queue->empty())
            {
                int now = current_queue->front();
                current_queue->pop();
                remain--;
 
                for (int next : nodes[now].next)
                {
                    nodes[next].depends_count--;
                    if (nodes[next].index < nodes[now].index)
                    {
                        must_next.insert(nodes[next].index);
                    }
 
                    if (nodes[next].depends_count == 0)
                    {
                        if (must_next.find(nodes[next].index) != must_next.end())
                        {
                            next_queue->push(next);
                        }
                        else
                        {
                            current_queue->push(next);
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
 
    Resolution resolution = Resolution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        resolution.run();
    }
    return 0;
}