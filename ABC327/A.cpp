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
    string s;
    bool ok = false;
    cin >> n >> s;
    rep(i,n-1)
    {
        if(s[i] == 'a' && s[i+1] == 'b')
        {
            ok = true;
        }
        if(s[i] == 'b' && s[i+1] == 'a')
        {
            ok = true;
        }
    }
    YesNo(ok);
    return 0;
}