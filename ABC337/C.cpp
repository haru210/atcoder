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
    int n;
    cin >> n;
    int a[n];
    int table[n+1];
    vector<int> ans;
    rep(i,n)
    {
        cin >> a[i];
        if(a[i] == -1) ans.push_back(i + 1);
        else table[a[i]] = i + 1;
    }
    rep(i,n-1)
    {
        //一番目の人がansの最後尾にいるので、table[ans[size()-1]]を参照
        int ne = table[ans[ans.size()-1]];
        ans.push_back(ne);
    }
    rep(i,ans.size()-1) cout << ans[i] << ' ';
    cout << ans[ans.size()-1] << endl;
    return 0;
}