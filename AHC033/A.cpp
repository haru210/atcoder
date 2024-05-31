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
    int a[n][n];
    pint place[25];
    rep(i, n) rep(j, n)
    {
        cin >> a[i][j];
        place[a[i][j]] = {i, j};
    }
    string ans[n];
    rep(i, n)
    {
        ans[i] = "";
        rep(j, 5)
        {
            ans[i] += "PRRRRQLLLL";
        }
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}