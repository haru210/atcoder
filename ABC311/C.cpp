#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 
int dfs(int g[],int v);

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int seen[200000] = {0}; //未訪問1、訪問済み1,現ループで探索済み2
bool finded = false;
int close_start;
vector<int> loot;
int main()
{
    int n;
    cin >> n;
    int graph[n];
    rep(i,n)
    {
        int tmp;
        cin >> tmp;
        tmp--;
        graph[i] = tmp;
    }
    rep(i,n)
    {
        if(seen[i] != 0) continue;
        loot.push_back(i + 1);

        dfs(graph,i);
        if(finded) break;
        loot.pop_back();
    }
    bool started = false;
    bool started_cnt = false;
    int cnt = 0;
    for(auto& val: loot)
    {
        if(val == close_start) started_cnt = true;
        if(!started_cnt) continue;
        cnt++;
    }
    cout << cnt << endl;
    cout << close_start;
    for(auto& val: loot)
    {
        if(val == close_start) {
            started = true;
            continue;
        }
        if(!started) continue;
        cout << ' ' <<val;
    }
    cout << endl;
    return 0;
}

int dfs(int g[],int v)
{
    if(finded) return 0;
    seen[v] = 2;
    int next_v;

    next_v  = g[v];
    if(seen[next_v] == 2)
    {
        finded = true;
        close_start = next_v + 1;
        return 0;
    }
    else 
    {
        loot.push_back(next_v + 1);
        if(next_v == 0) cout << "now\n";
        dfs(g,next_v);
        if(finded) return 0;
        seen[v] = 1;
        loot.pop_back();
    }
    return 0;
}