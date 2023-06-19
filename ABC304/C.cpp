#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void dfs(Graph& g, int v);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;


bool infected[2000] = {0};
int main()
{
    int n, d;
    int x[2000], y[2000];
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
        dfs(person, 0);
    rep(i, n)
    {
        if(infected[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

void dfs(Graph& g, int v)
{
    infected[v] = true; 
    int next_v;
    for(int i = 0; i < g[v].size(); i++)
    {
        next_v = g[v][i];
        if(infected[next_v] == false)
        {
            dfs(g, next_v);
        }
    }
}