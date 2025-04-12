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
    bool be_login = false;
    int ans = 0;
    cin >> n;
    rep(i, n)
    {
        string s;
        cin >> s;
        if(s == "login")
        {
            be_login = true;
        }
        else if(s == "logout")
        {
            be_login = false;
        }
        else if(s == "private" && !be_login)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}