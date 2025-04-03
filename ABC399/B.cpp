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
    pint p[n];
    rep(i, n)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p, p + n, greater<pint>());
    int rank[n] = {};
    int nrank = 1;
    rep(i, n)
    {
        rank[p[i].second] = nrank;
        if(i == n - 1) continue;
        if(p[i + 1].first != p[i].first) nrank = i + 2; 
    }
    rep(i, n)
    {
        cout << rank[i] << endl;
    }
    return 0;
}