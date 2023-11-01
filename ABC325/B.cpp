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
    int n;
    cin >> n;
    int w[n], x[n];
    rep(i,n) cin >> w[i] >> x[i];
    int ans = -1;
    rep(i,24)
    {
        int cnt = 0;
        rep(j,n)
        {
            int localtime = (i + x[j]) %24; //現地時間で会議が始まる時間
            if(localtime >= 9 && localtime + 1 <= 18)
            {
                cnt += w[j];
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}