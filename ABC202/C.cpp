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
    ll sum = 0;
    cin >> n;
    int a[n],b[n],c[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) {cin >> c[i]; c[i]--;}
    //CでアクセスできるBの個数をカウント
    map<int,ll> cnt;
    rep(i,n)
    {
        cnt[b[c[i]]] += 1;
    }
    rep(i,n)
    {
        sum += cnt[a[i]];
    }
    cout << sum << endl;
    return 0;
}