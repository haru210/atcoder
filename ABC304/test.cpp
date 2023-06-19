#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void dfs(Graph g, int v, bool now, int before);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

bool seen[2000] = {false};
bool infected[2000] = {0};
int main()
{
    int n, d;
    int x[1000], y[1000];
    infected[0] = true;
    cin >> n >> d;
    Graph person(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    rep(i, n)
    {
        rep(j, n)
        {
            if(i == j) break;
            if(sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2)) <= d)
            {
                person[i].push_back(j);
                person[j].push_back(i);
            }
        }
    }
    rep(i, n)
     {
        seen[i] = false;
    }
    rep(i, n)
    {
        dfs(person, i, infected[i], -1);
    }
    rep(i, n)
    {
        if(infected[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

void dfs(Graph g, int v, bool now, int before)
{
    if(now) {
        infected[v] = true; 
        if(v == 4)   cout << before << endl;

    }
    else return;
    now = infected[v];
    int next_v;
    seen[v] = true;
    for(int i = 0; i < g[v].size(); i++)
    {
        next_v = g[v][i];
        if(seen[next_v] == false)
        {
            dfs(g, next_v, now, v);
        }
    }
}