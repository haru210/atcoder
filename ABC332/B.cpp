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
    int k,g,m;
    cin >> k >> g >> m;
    int gl = 0, mug = 0;
    rep(i,k)
    {
        if(gl == g) gl = 0;
        else if(mug == 0) mug = m;
        else
        {
            if(g -gl > mug)
            {
                //全部入れられる
                gl += mug;
                mug = 0;
            }
            else
            {
                //マグカップのほうが多い
                mug -= g - gl;
                gl = g;
            }
        }
    }
    cout << gl  << ' '<< mug << endl;
    return 0;
}