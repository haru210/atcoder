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
    int n, t, p;
    cin >> n >> t >> p;
    int l[n];
    rep(i, n) cin >> l[i];
    int cnt = 0;
    rep(i, n)
    {
        if(l[i] >= t) cnt++;
    }
    if(cnt >= p) cout << 0 << endl;
    else
    {
        int day = 1;
        while(true)
        {
            rep(i, n)
            {
                l[i]++;
                if(l[i] == t) cnt++;
            }
            if(cnt >= p)
            {
                cout << day << endl;
                break;
            }
            day++;
        }
    }
    return 0;
}