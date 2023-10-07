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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ll blue = a;
    ll red = 0;
    int cnt;
    bool ok = false;
    rep(i,1000000)
    {
        if(red * d >= blue)
        {
            ok = true;
            cnt = i;
            break;
        }
        blue += b;
        red += c;
    }
    if(!ok) cout << -1 << endl;
    else cout << cnt << endl;
    return 0;
}