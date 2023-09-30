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
    int n,m;
    bool head = false;
    bool back = false;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    bool ok = true;
    rep(i,n)
    {
        if(t[i] != s[i])
        {
            ok = false;
            break;
        }
    }
    if(ok) head = true;
    int cnt = 0;
    ok = true;
    for(int i = (m - n); i < m; i++)
    {
        if(t[i] != s[cnt]) 
        {
            ok = false;
            break;   
        }
        cnt++;
    }
    if(ok) back = true;
    if(head && back) cout << 0 << endl;
    else if(head) cout << 1 << endl;
    else if(back) cout << 2 << endl;
    else cout << 3 << endl;
    return 0;
}