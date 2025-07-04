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
    int n, m;
    cin >> n >> m;
    int l[m], r[m];
    int sum[n + 1] = {};
    rep(i, m) cin >> l[i] >> r[i];
    rep(i, m)
    {
        sum[l[i]]++;
        if(r[i] != n) sum[r[i] + 1]--;
    }
    rep(i, n + 1)
    {
        sum[i + 1] += sum[i];
    }
    int msum = inf;
    rep2(i, n)
    {
        msum = min(msum, sum[i]);
    }
    cout << msum << endl;
    return 0;
}