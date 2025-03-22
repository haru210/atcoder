#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
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
    int p[n + 1], q[n + 1];
    rep2(i, n) cin >> p[i];
    rep2(i, n) cin >> q[i];
    int ord[n + 1] = {};
    rep2(i, n)
    {
        ord[q[i]] = i;
    }
    rep2(i, n)
    {
        cout << q[p[ord[i]]] << ' ';
    }
    return 0;
}