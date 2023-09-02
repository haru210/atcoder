#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//順番は関係ないので、sortして小さい順に周遊パスを使う？
//
int main()
{
    int n,d,p;
    cin >> n >> d >> p;
    int f[n];
    ll ans = 0;
    rep(i,n)
    {
        cin >> f[i];
    }
    sort(f,f+n,greater<int>());
    for(int i = 0; i < n;)
    {
        ll normal = 0;
        ll path = 0;
        for(int j = i;j < min(i+d,n); j++)
        {
            normal += f[j];
        }
        path += p;
        if(path < normal) ans += path;
        else ans += normal;
        i += d;
    }
    cout << ans << endl;
    return 0;
}