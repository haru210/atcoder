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
    string s;
    cin >> s;
    int phase = 0;
    bool isA = false;
    bool isB = false;
    bool isC = false;
    bool ok = true;
    rep(i,s.size())
    {
        if(s[i] == 'A') isA = true;
        if(s[i] == 'B') isB = true;
        if(s[i] == 'C') isC = true;
        if(s[i] == 'A' && (isB || isC)) ok = false;
        if(s[i] == 'B' && isC) ok = false;
    }
    YesNo(ok);
    return 0;
}