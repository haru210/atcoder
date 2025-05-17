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
    //nが小さい
    int h, w, n;
    cin >> h >> w >> n;
    int x[n], y[n];
    int first_row[h];
    int first_column[w];
    rep(i, h) first_row[i] = inf;
    rep(i, w) first_column[i] = inf;
    rep(i, n) 
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    int q;
    cin >> q;
    ll ans[q]= {};
    rep(i, q)
    {
        int query, num;
        cin >> query >> num;
        num--;
        if(query == 1)
        {
            first_row[num] = min(first_row[num], i);
        }
        else
        {
            first_column[num] = min(first_column[num], i);
        }
    }
    rep(i, n)
    {
        if(first_row[x[i]] != inf || first_column[y[i]] != inf)
        {
            int tmp = min(first_row[x[i]], first_column[y[i]]);
            ans[tmp]++;
        }
    }
    rep(i, q)
    {
        cout << ans[i] << endl;
    }
    return 0;
}