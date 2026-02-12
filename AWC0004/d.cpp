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

bool lr_comp(const pint& i, const pint& j)
{
    if (i.second != j.second)
    {
        return i.second < j.second;
    }
    else
    {
        return i.first < j.first;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    pint lr[m];
    rep(i, m)
    {
        cin >> lr[i].first >> lr[i].second;
    }
    sort(lr, lr + m, lr_comp);
    set<int> sp;
    rep2(i, n + 1) sp.insert(i);
    bool ok = true;
    rep(i, m)
    {
        pint tmp = lr[i];
        auto l_lim = sp.lower_bound(lr[i].first);
        if ((*l_lim) > lr[i].second)
        {
            ok = false;
            break;
        }
        else
        {
            sp.erase(l_lim);
        }
    }
    YesNo(ok);
    return 0;
}
