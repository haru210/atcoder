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
    string s;
    cin >> s;
    rep(i, 26)
    {
        bool ok = true;
        rep(j, s.size())
        {
            if(s[j] == (char)('a' + i))
            {
                ok = false;
            }
        }
        if(ok)
        {
            cout << (char)('a' + i) << endl;
            break;
        }
    }
    return 0;
}