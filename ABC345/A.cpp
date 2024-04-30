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
    bool ok = true;
    cin >> s;
    if(s.size() <= 2) ok = false;
    else
    {
        if(s[0] != '<')
        {
            ok = false;
        }
        if(s[s.size()-1] != '>')
        {
            ok = false;
        }
        for(int i = 1; i < s.size() -1 ; i++)
        {
            if(s[i] != '=') ok = false;
        }
    } 
    YesNo(ok);
    return 0;
}