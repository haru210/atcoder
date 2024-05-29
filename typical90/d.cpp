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

int main()
{
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];
    int row[h] = {};
    int column[w] = {};
    rep(i, h)
    {
        rep(j, w)
        {
            row[i] += a[i][j];
            column[j] += a[i][j];
        }
    }
    rep(i, h)
    {
        rep(j, w - 1)
        {
            cout << row[i] + column[j] - a[i][j] << ' ';
        }
        cout << row[i] + column[w - 1] - a[i][w - 1] << endl;
    }
    return 0;
}