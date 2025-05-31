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
    int n, s;
    cin >> n >> s;
    int t[n];
    bool ok = true;
    rep(i, n) cin >> t[i];
    if(t[0] > s) ok = false;
    rep2(i, n - 1)
    {
        if(t[i] - t[i - 1] > s) ok = false;
    }
    YesNo(ok);
    return 0;
}