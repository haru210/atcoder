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
    int n,m;
    string s;
    cin >> n >> m >> s;
    //自明に1000枚持っていればいけます
    int ng = -1;
    int ok = 1001;
    while(ok - ng > 1)
    {
        int mid = ng + (ok - ng) / 2;
        bool ans = true;
        int white = m;
        int logo = mid;
        rep(i,n)
        {
            if(s[i] == '0')
            {
                white = m;
                logo = mid;
            }
            if(s[i] == '1')
            {
                if(white != 0) white--;
                else if(logo != 0) logo--;
                else ans = false;
            }
            if(s[i] == '2')
            {
                if(logo != 0) logo--;
                else ans = false;
            }
            if(!ans) break;
        }
        if(ans) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
} 