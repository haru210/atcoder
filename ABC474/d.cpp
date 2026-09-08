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

//高橋君の持ってる石の重みを10^18,そうでない物を1とすると、
//n=10^9で、A_1=B_1+1, A_i=1, B_i=10^9(iは1以外)のとき、
//10^18-(10^9-1)*10^9>=0なので、1個でもでかければOK
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    bool ok = false;
    rep(i, n)
    {
        if (a[i] > b[i]) ok = true;
    }
    if (!ok)
    {
        cout << "No\n";
        return 0;
    }
    else
    {
        cout << "Yes\n";
        rep(i, n)
        {
            if (a[i] > b[i]) cout << 1000000000000000000LL;
            else cout << 1LL;
            if (i != n - 1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
