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
    int n;
    cin >> n;
    int p[n];
    rep(i,n) cin >> p[i];
    int one = p[0];
    sort(p,p+n,greater<int>());
    if(one == p[0])
    {
        if(p[0] == p[1]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else cout << p[0] - one +1 << endl;
    return 0;
}