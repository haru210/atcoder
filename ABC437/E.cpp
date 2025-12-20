#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

vector<int> ans;
void dfs(vector<vector<pint>>& g, queue<pint>& to_search)
{
    priority_queue<pint, vector<pint>, greater<pint>> que;
    while(!to_search.empty())
    {
        pint v = to_search.front();
        to_search.pop();
        for(auto& nv: g[v.second])
        {
            que.push(nv);
        }
    }
    if(que.size() != 0)
    {
        int now_y = que.top().first;
        queue<pint> n_search;
        while(!que.empty())
        {
            pint nv = que.top();
            que.pop();
            if(nv.first == now_y)
            {
                ans.push_back(nv.second);
                n_search.push(nv);
            }
            else
            {
                dfs(g, n_search);
                now_y = nv.first;
                n_search.push(nv);
                ans.push_back(nv.second);
            }
        }
        if(!n_search.empty())
        {
            dfs(g, n_search);
        }
    }
}

int main()
{
    //グラフにする
    //辞書順で小さい順に回りたい
    //テストケース1の2->4->3が面倒
    int n;
    cin >> n;
    vector<vector<pint>> g(n + 1);
    rep2(i, n)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back({y, i});
    }
    queue<pint> tmp;
    tmp.push({0, 0});
    dfs(g, tmp);
    rep(i, ans.size())
    {
        cout << ans[i] << ' ';
    }
    return 0;
}