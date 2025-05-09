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

//a1, a2, a3, a4...がa1:a2 = a2:a3...なら良いので、a[i] * a[i + 2] == a[i + 1] ^ 2ならば良い
int main()
{
    int n;
    cin >> n;
    ll a[n];
    rep(i, n)
    {
        cin >> a[i];
    }
    bool ok = true;
    rep(i, n - 2)
    {
        if(a[i] * a[i + 2] != a[i + 1] * a[i + 1]) ok = false;
    }
    YesNo(ok);
    return 0;
}