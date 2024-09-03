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
    int n;
    cin >> n;
    int a[n];
    char s[n];
    rep(i, n) cin >> a[i] >> s[i];
    int l = -1;
    int r = -1;
    int ans = 0;
    rep(i, n)
    {
        if(s[i] == 'L')
        {
            if(l == -1)
            {
                l = a[i];
            }
            else
            {
                ans += abs(l - a[i]);
                l = a[i];
            }
        }
        else
        {
            if(r == -1)
            {
                r = a[i];
            }
            else
            {
                ans += abs(r - a[i]);
                r = a[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}