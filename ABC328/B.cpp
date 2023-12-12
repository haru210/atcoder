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
    int n;
    cin >> n;
    int d[n+1];
    int ans = 0;
    rep2(i,n) cin >> d[i];
    rep2(i,n)
    {
        rep2(j,d[i])
        {
            if(i < 10)
            {
                if(j < 10)
                {
                    if(i == j) ans++;
                }
                else
                {
                    if((j %11) == 0 && i == (j % 10)) ans++;
                }
            }
            else
            {
                if(i % 11 == 0)
                {
                    if(j < 10)
                    {
                        if(i % 10 == j) ans++;
                    }
                    else
                    {
                        if(i % 10 == j % 10 && j % 11 == 0) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}