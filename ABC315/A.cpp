#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

char clear[5] = {'a','e','i','o','u'};
int main()
{
    string s;
    cin >> s;
    rep(i,s.size())
    {
        bool key = true;
        rep(j,5)
        {
            if(s[i] == clear[j]) key = false;
        }
        if(key) cout << s[i];
    }
    cout << endl;
    return 0;
}