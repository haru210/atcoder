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
    int n, k;
    cin >> n >> k;
    int c[n];
    rep(i, n) cin >> c[i];
    map<int, int> can;
    int var = 0;
    int ans = -1;
    rep(i, k)
    {
        can[c[i]]++;
        if(can[c[i]] == 1) var++;
    }
    ans = var;
    for(int i = k; i < n; i++)
    {
        can[c[i]]++;
        if(can[c[i]] == 1) var++;
        can[c[i - k]]--;
        if(can[c[i - k]] == 0) var--;
        ans = max(ans, var);
    }
    cout << ans << endl;
    return 0;
}