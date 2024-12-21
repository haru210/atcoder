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


int main()
{
    ll h, w, x, p, q;
    cin >> h >> w >> x;
    cin >> p >> q;
    p--;
    q--;
    ll s[h][w];
    bool seen[h][w] = {};
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> s[i][j];
        }
    }
    ll str = 0;
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> que;
    que.push(make_pair(s[p][q], make_pair(p, q)));
    while(!que.empty())
    {
        pair<ll, pair<int, int>> v = que.top();
        que.pop();
        ll vpow = v.first;
        pint vpos = v.second;
        seen[vpos.first][vpos.second] = true;
        bool can_ab = false;
        if(str == 0) can_ab = true;
        else
        {
            if(str % x == 0)
            {
                if((str / x) > vpow) can_ab = true;
            }
            else
            {
                if((str / x) >= vpow) can_ab = true;
            }
        }
        if(!can_ab) continue;
        str += vpow;
        if(vpos.first != 0)
        {
            if(!seen[vpos.first - 1][vpos.second]) 
            {
                que.push(make_pair(s[vpos.first - 1][vpos.second], make_pair(vpos.first - 1, vpos.second)));
                seen[vpos.first - 1][vpos.second] = true;
            }
        }
        if(vpos.first != h - 1)
        {
            if(!seen[vpos.first + 1][vpos.second])
            {
                que.push(make_pair(s[vpos.first + 1][vpos.second], make_pair(vpos.first + 1, vpos.second)));
                seen[vpos.first + 1][vpos.second] = true;
            }
        }
        if(vpos.second != 0)
        {
            if(!seen[vpos.first][vpos.second - 1])
            { 
                que.push(make_pair(s[vpos.first][vpos.second - 1], make_pair(vpos.first, vpos.second - 1)));
                seen[vpos.first][vpos.second - 1] = true;            
            }
        }
        if(vpos.second != w - 1)
        {
            if(!seen[vpos.first][vpos.second + 1]) 
            {
                que.push(make_pair(s[vpos.first][vpos.second + 1], make_pair(vpos.first, vpos.second + 1)));
                seen[vpos.first][vpos.second + 1] = true;            
            }
        }
    }
    cout << str << endl;
    return 0;
}