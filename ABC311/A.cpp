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
    int n;
    string s;
    cin >> n >> s;
    bool a = false;
    bool b = false;
    bool c = false;
    rep(i,n)
    {
        if(s[i] == 'A') a = true;
        if(s[i] == 'B') b = true;
        if(s[i] == 'C') c = true;
        if(a && b && c) {cout << i + 1 << endl; break;}
    }
    return 0;
}