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
    int n, m;
    cin >> n >> m;
    ll sx, sy;
    cin >> sx >> sy;
    map<ll, set<ll>> row;
    map<ll, set<ll>> column;
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        row[y].insert(x);
        column[x].insert(y);
    }
    int ans = 0;
    rep(i, m)
    {
        char d;
        int c;
        cin >> d >> c;
        if(d == 'U')
        {
            set<ll>& ctmp = column[sx];
            auto before = ctmp.lower_bound(sy);
            auto after = ctmp.upper_bound(sy + c);
            while(after != before)
            {
                ll ytmp = (*before);
                before = ctmp.erase(before);
                row[ytmp].erase(sx);
                ans++;
            }
            sy += c;
        }
        if(d == 'D')
        {
            set<ll>& ctmp = column[sx];
            auto before = ctmp.lower_bound(sy - c);
            auto after = ctmp.upper_bound(sy);
            while(after != before)
            {
                ll ytmp = (*before);
                before = ctmp.erase(before);
                row[ytmp].erase(sx);
                ans++;
            }
            sy -= c;
        }
        if(d == 'L')
        {
            set<ll>& rtmp = row[sy];
            auto before = rtmp.lower_bound(sx - c);
            auto after = rtmp.upper_bound(sx);
            while(after != before)
            {
                ll xtmp = (*before);
                before = rtmp.erase(before);
                column[xtmp].erase(sy);
                ans++;
            }
            sx -= c;
        }
        if(d == 'R')
        {
            set<ll>& rtmp = row[sy];
            auto before = rtmp.lower_bound(sx);
            auto after = rtmp.upper_bound(sx + c);
            while(after != before)
            {
                ll xtmp = (*before);
                before = rtmp.erase(before);
                column[xtmp].erase(sy);
                ans++;
            }
            sx += c;
        }
    }
    cout << sx << ' ' << sy << ' ';
    cout << ans << endl;
    return 0;
}