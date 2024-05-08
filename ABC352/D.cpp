#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

//より狭い幅でk個の連続する数字の並び替えを見つけるゲーム
ll dat1[1000000];
ll dat2[1000000];

class SegmentTree {
    public:
    ll siz = 1;
    int tp;

    void init(ll n){
        siz = 1;
        while(siz < n) siz *= 2;
        for(ll i = 1; i < siz * 2; i++)
        {
            if(tp == 0) dat1[i] = 0;
            else dat2[i] = inf;
        }
    }

    void update(ll pos, ll x){
        pos = pos + siz - 1;
        if(tp == 0) dat1[pos] = x;
        else dat2[pos] = x;
        while(pos >= 2)
        {
            pos /= 2;
            if(tp == 0) //最大値
            {
                dat1[pos] = max(dat1[pos * 2], dat1[pos * 2 + 1]);
            }
            if(tp == 1) //最小値
            {
                dat2[pos] = min(dat2[pos * 2], dat2[pos * 2 + 1]);
            }
        }
    }

    ll query(ll l, ll r, ll a, ll b, ll u)
    {
        if(r <= a || b <= l)
        {
            if(tp == 0) return -l_inf;
            if(tp == 1) return l_inf;
        }
        if(l <= a && b <= r)
        {
            if(tp == 0) return dat1[u];
            else return dat2[u];
        } 
        ll m = (a + b) / 2;
        ll al = query(l, r, a, m, u * 2);
        ll ar = query(l, r, m, b, u * 2 + 1);
        if(tp == 0) return max(al, ar);
        if(tp == 1) return min(al, ar);
        return -1;
    }
};
int main()
{
    ll ans = inf;
    int n, k;
    cin >> n >> k;
    pint p[n+100];
    
    rep2(i, n)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + n + 1);
    SegmentTree zmin;
    SegmentTree zmax;
    zmin.tp = 1;
    zmax.tp = 0;
    zmin.init(n);
    zmax.init(n);
    rep2(i, n)
    {
        zmin.update(p[i].first, p[i].second);
        zmax.update(p[i].first, p[i].second);
    }
    for(int i = 1; i <= (n - k + 1); i++)
    {
       ll tmp = zmax.query(i, i + k , 1, zmax.siz + 1, 1) - zmin.query(i, i+ k, 1, zmin.siz + 1, 1); 
       ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}