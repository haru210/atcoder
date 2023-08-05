#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

string tmp[7] = {"ACE","BDF","CEG","DFA","EGB","FAC","GBD"};
int main()
{
    string s;
    cin >> s;
    bool ok = false;
    rep(i,7)
    {
        if(tmp[i] == s) ok = true;
    }
    YesNo(ok);
    return 0;
}