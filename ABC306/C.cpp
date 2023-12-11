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
    int a[3 * n];
    int cnt[n+1] = {};
    vector<pint> s_index; //first添え字,second数字
    rep(i,3 * n) cin >> a[i];
    rep(i,3 * n)
    {
        cnt[a[i]]++;
        if(cnt[a[i]] == 2)
        {
            s_index.push_back(make_pair(i, a[i]));
        }
    }
    sort(s_index.begin(), s_index.end());
    rep(i,s_index.size())
    {
        cout << s_index[i].second << endl;
    }
    return 0;
}