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
    int n, q;
    cin >> n;
    int p[n];
    rep(i,n)
    {
        cin >> p[i];
    } 
    cin >> q;
    int a[q], b[q];
    rep(i,q) cin >> a[i] >> b[i];
    rep(i,q)
    {
        rep(j,n)
        {
            if(p[j] == a[i])
            {
                cout << a[i] << endl;
                break;
            }
            if(p[j] == b[i])
            {
                cout << b[i] << endl;
                break;
            }
        }
    }
    return 0;
}