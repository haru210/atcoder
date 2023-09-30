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
    rep(i,n - 2)
    {
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C')
        {
            ok = true;
            cout << i+1 << endl;
            break;
        }
    }
    if(!ok) cout << -1 << endl;
    return 0;
}