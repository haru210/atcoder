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
    int n, t;
    cin >> n >> t;
    int row[n] = {};
    int column[n] = {};
    int diag[2] = {}; //0->左上右下 1->右上左下
    int a[t];
    bool ok = false;
    rep(i, t) cin >> a[i];
    rep(i, t)
    {
        int h = (a[i] - 1) / n;
        int w = (a[i] - 1) % n;
        row[h]++;
        if(row[h] == n) ok = true;
        column[w]++;
        if(column[w] == n) ok = true;
        if(h == w) 
        {
            diag[0]++;
        }
        if(diag[0] == n) ok = true;
        w = (n - 1) - w;
        if(h == w)
        {
            diag[1]++;
        }
        if(diag[1] == n) ok = true;
        if(ok)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    if(!ok) cout << -1 << endl;
    return 0;
}