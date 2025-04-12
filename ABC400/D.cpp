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

//dp[i][j] := (i, j)に到達できる前蹴りの最小回数
int y[4] = {1, -1, 0, 0};
int x[4] = {0, 0, 1, -1};
int main()
{
    int h, w;
    int a, b, c, d;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    int dp[h][w] = {};
    rep(i, h)
    {
        rep(j, w)
        {
            dp[i][j] = inf;
        }
    }
    priority_queue<pair<int, pint>, vector<pair<int, pint>>, greater<pair<int, pint>>> que;
    que.push({0, {a, b}});
    dp[a][b] = 0;
    while(!que.empty())
    {
        pair<int, pint> tmp = que.top();
        que.pop();
        pint v = tmp.second;
        rep(i, 4)
        {
            pint tmpv = v;
            tmpv.first += y[i];
            tmpv.second += x[i];
            if(tmpv.first < 0 || tmpv.first >= h || tmpv.second < 0 || tmpv.second >= w) continue;
            if(s[tmpv.first][tmpv.second] == '.')
            {
                if(dp[tmpv.first][tmpv.second] > dp[v.first][v.second])
                {
                    dp[tmpv.first][tmpv.second] = dp[v.first][v.second];
                    que.push({dp[v.first][v.second], {tmpv.first, tmpv.second}});
                } 
            }
            else
            {
                //前蹴りする
                if(dp[tmpv.first][tmpv.second] > dp[v.first][v.second] + 1)
                {
                    dp[tmpv.first][tmpv.second] = dp[v.first][v.second] + 1;
                    que.push({dp[v.first][v.second] + 1, {tmpv.first, tmpv.second}});
                }
                //2個前
                tmpv.first += y[i];
                tmpv.second += x[i];
                if(!(tmpv.first < 0 || tmpv.first >= h || tmpv.second < 0 || tmpv.second >= w) && (dp[tmpv.first][tmpv.second] > dp[v.first][v.second] + 1))
                {
                    
                    dp[tmpv.first][tmpv.second] = dp[v.first][v.second] + 1;
                    que.push({dp[v.first][v.second] + 1, {tmpv.first, tmpv.second}});    
                }
            }
        }
    }
    cout << dp[c][d] << endl;
    return 0;
}