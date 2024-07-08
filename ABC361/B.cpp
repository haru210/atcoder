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
    int a[6], b[6];
    rep(i, 6) cin >> a[i];
    rep(i, 6) cin >> b[i];
    bool ok = false;
    if((b[3] <= a[0])) ok = true;
    if((a[3] <= b[0])) ok = true;
    if((b[4] <= a[1])) ok = true;
    if((a[4] <= b[1])) ok = true;
    if((b[5] <= a[2])) ok = true;
    if((a[5] <= b[2])) ok = true;
    YesNo((!ok));
    return 0;
}