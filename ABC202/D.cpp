#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

ll aCb(int a,int b);

ll memo[61][61];
int main()
{
    int a,b;
    int n;
    ll k;
    string ans = "";
    cin >> a >> b >> k;
    n = a+b;
    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= n;j++)
        {
            memo[i][j] = -1;
        }
    }
    for(int i = 0; i <= n;i++)
    {
        memo[i][0] = 1;
        if(i != 0)
        {
            memo[i][1] = i;
        }
        memo[i][i] = 1;
    }
    rep(i,n){
        if(a == 0) 
        {
            ans += 'b';
            b--;
        }
        else {
            if(aCb(a-1+b,b) >= k)
            {
                ans += 'a';
                a--;
            }
            else if(aCb(a-1+b,b) < k)
            {
                ans += 'b';
                k -= (aCb(a-1+b,b));
                b--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

ll aCb(int a,int b)
{
    if(memo[a][b] != -1) return memo[a][b];
    else
    {
        memo[a][b] = aCb(a-1,b-1) + aCb(a-1,b);
        return memo[a][b];
    }
}