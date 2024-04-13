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
    string s,t;
    bool is_x = false;
    bool ok = false;
    cin >> s >> t;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    if(t[2] == 'X') is_x = true;
    if(!is_x)
    {
        int p = 0;
        rep(i,s.size())
        {
            if(s[i] == t[p])
            {
                if(p == 2) ok = true;
                else p++;
            }
        }
    }
    else
    {
        int p = 0;
        rep(i,s.size())
        {
            if(s[i] == t[p])
            {
                if(p == 1) ok = true;
                else p++;
            }
        }
    }
    YesNo(ok);
    return 0;
}