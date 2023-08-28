#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int a,b,n;
    cin >> a >> b >> n;
    ll dp[a+1][b+1] = {0};
    bool isStopped[a+1][b+1] = {false};
    rep(i,n)
    {
        int x,y;
        cin >> x >> y;
        isStopped[x][y] = true;
    }
    dp[1][1] = 1;
    for(int y = 1; y <= b; y++)
    {
        for(int x = 1; x <= a;x++)
        {
            if(isStopped[x][y]) 
            {
                dp[x][y] = 0;
                continue;
            }
            if(x!= 1)
            {
                dp[x][y] += dp[x-1][y];
            } 
            if(y!= 1)
            {
                dp[x][y] += dp[x][y-1];
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}