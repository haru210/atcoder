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
    int n, r;
    cin >> n >> r;
    int rat = r;
    int d[n], a[n];
    rep(i, n)
    {
        cin >> d[i] >> a[i];
    }
    rep(i, n)
    {
        if(d[i] == 1)
        {
            if(1600 <= rat && rat <= 2799)
            {
                rat += a[i];
            }
        }
        if(d[i] == 2)
        {
            if(1200 <= rat && rat <= 2399)
            {
                rat += a[i];
            }
        }
    }
    cout << rat << endl;
    return 0;
}