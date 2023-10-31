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
int main()
{
    int m,n;
    cin >> m;
    pint correct[m]; //(y,x)
    map<pint, bool> is_star;
    rep(i,m)
    {
        cin >> correct[i].second >> correct[i].first;
    }
    cin >> n;
    pint all[n];
    rep(i,n)
    {
        cin >> all[i].second >> all[i].first;
        is_star[all[i]] = true;
    }
    sort(correct, correct+m);
    sort(all, all+n);
    for(int i = 0; i < n; i++)
    {
        bool ok = true;
        int delta_x = correct[0].second - all[i].second;
        int delta_y = correct[0].first - all[i].first;

        //まずどれだけ平行移動すべきか計算
        for(int j = 0; j < m; j++)
        {
            if(!is_star[make_pair(correct[j].first-delta_y, correct[j].second-delta_x)])
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << -delta_x << ' ' << -delta_y << endl;
            break;
        }
    }
    return 0;
}