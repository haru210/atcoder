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
    int n, x;
    cin >> n >> x;
    int a[n+1];
    rep2(i, n) cin >> a[i];
    int sum = 0;
    rep2(i, n)
    {
        if(i % 2 == 0) sum += (a[i] - 1);
        else sum += a[i];
    }
    bool ok = true;
    if(sum > x) ok = false;
    YesNo(ok);
    return 0;
}