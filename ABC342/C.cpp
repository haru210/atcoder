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
    int n,q;
    string s;
    cin >> n >> s >> q;
    char c[q], d[q];
    rep(i,q) cin >> c[i] >> d[i];
    //各文字が何になるか探索
    int ch[26];
    rep(i,26) ch[i] = i;
    rep(i,26)
    {
        rep(j,q)
        {
            if(c[j] - 'a' == ch[i])
            {
                ch[i] = d[j] - 'a';
            }
        }
    }
    rep(i,n)
    {
        int chnum = s[i] - 'a';
        cout << (char)(ch[chnum] + 'a');
    }
    cout << endl;
    return 0;
}