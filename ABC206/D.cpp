#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

vector<vector<int>> g(200010);
bool seen[200010] = {false};
void dfs(int v)
{
    seen[v] = true;
    int next_v;
    rep(i,g[v].size())
    {
        next_v = g[v][i];
        if(!seen[next_v]) dfs(next_v);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i,n)
    {
        cin >> a[i];
    } 
    int left = 0;
    int right = n-1;
    set<int> cnt;
    set<pair<int,int>> line;
    while(right > left)
    {
        if(a[left] != a[right])
        {
            cnt.insert(a[left]);
            cnt.insert(a[right]);
            line.insert(make_pair(a[left],a[right]));
            line.insert(make_pair(a[right],a[left]));
        } 
        left++;
        right--;
    }
    for(const auto & val : line)
    {
        g[val.first].push_back(val.second);
        g[val.second].push_back(val.first);
    }
    int chain_cnt = 0;
    for(const auto & v:cnt)
    {
        if(!seen[v])
        {
            dfs(v);
            chain_cnt++;
        }
    }
    cout << cnt.size() - chain_cnt << endl;
    return 0;
}
