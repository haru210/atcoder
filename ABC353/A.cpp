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
    int n;
    cin >> n;
    bool ok = false;
    int h[n];
    rep(i, n)
    {
        cin >> h[i];
    }
    rep2(i, n- 1)
    {
        if(h[i] > h[0])
        {
            ok = true;
            cout << i + 1 << endl;
            break;
        }
    }
    if(!ok) cout << -1 << endl;
    return 0;
}