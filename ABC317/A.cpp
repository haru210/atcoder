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
    int n,h,x;
    cin >> n >> h >> x;
    int p[n];
    rep(i,n) cin >> p[i];
    rep(i,n)
    {
        if(h + p[i] >= x)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}