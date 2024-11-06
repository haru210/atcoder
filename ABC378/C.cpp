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
    int a[n + 1];
    rep2(i, n) cin >> a[i];
    map<int, int> pos;
    vector<int> ans;
    rep2(i, n)
    {
        if(pos[a[i]] == 0)
        {
            ans.push_back(-1);
            pos[a[i]] = i;
        }
        else
        {
            ans.push_back(pos[a[i]]);
            pos[a[i]] = i;
        }
    }
    rep(i, n)
    {
        cout << ans[i];
        if(i != n - 1) cout << ' ';
        else cout << endl;
    }
    return 0;
}