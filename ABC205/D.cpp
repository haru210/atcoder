#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,q;
    cin >> n >> q;
    ll a[n];
    ll k[q];
    rep(i,n) cin >> a[i];
    rep(i,q) cin >> k[i];
    ll c[n];
    rep(i,n)
    {
        c[i] = a[i] - (i + 1);
    }
    rep(i,q)
    {
        //k[i] > c[i]のとき、a[n-1]以降はすべてカウントするので、
        //a[n-1]までにc[n-1]カウントし、それ以降はk[i] - c[n-1]こカウントする必要があるので、
        if(k[i] > c[n-1]) cout << k[i] + n<< endl;
        else
        {
            int index;
            index = lower_bound(c,c+n,k[i]) - c;
            //c[index] == k のときans = a[index] - 1
            //そこから足りない分を引く
            cout << a[index] - 1 - (c[index] - k[i]) << endl;
        }
    }
    return 0;
}