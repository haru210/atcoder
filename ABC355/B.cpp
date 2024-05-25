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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    bool ok = false;
    vector<int> c;
    bool isA[210] = {};
    rep(i, n)
    {
        cin >> a[i];
        c.push_back(a[i]);
        isA[a[i]] = true;
    }
    rep(i, m)
    {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    rep(i, c.size() - 1)
    {
        if(isA[c[i]] && isA[c[i+1]]) ok = true;
    }
    YesNo(ok);
    return 0;
}