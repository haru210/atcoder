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
    int n,d;
    cin >> n >> d;
    string s[n];
    rep(i,n) cin >> s[i];
    int m_chain = 0,chain = 0;
    bool key = false;
    rep(i,d)
    {
        key =true;
        rep(j,n)
        {
            if(s[j][i] == 'x')
            {
                key = false;
                chain = 0;
            }
        }
        if(key)
        {
            chain++;
        }
        m_chain = max(chain,m_chain);
    }
    cout << m_chain << endl;
    return 0;
}