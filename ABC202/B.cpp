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
    string s;
    string ans = "";
    cin >> s;
    reverse(s.begin(),s.end());
    rep(i,s.size())
    {
        if(s[i] == '6') ans += '9';
        else if(s[i] == '9') ans += '6';
        else ans += s[i];
    }
    cout << ans << endl;
    return 0;
}