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
//各コスト必要な強さを作る->満たないやつは切
int main()
{
    int n;
    cin >> n;
    int a[n], c[n]; //コスト、強さ
    pint c_co[n];
    rep(i, n) 
    {
        cin >> a[i] >> c[i];
        c_co[i].first = c[i];
        c_co[i].second = a[i];
    }
    sort(c_co, c_co + n);
    int cc[n];
    rep(i, n) cc[i] = c_co[i].first;
   vector<int> bordera;

    rep(i,n)
    {
        bordera.push_back(c_co[i].second);
        if(bordera.size() == 1) continue;
        if(bordera[bordera.size() - 1] < bordera[bordera.size() - 2])
        {
            bordera[bordera.size() - 1] = bordera[bordera.size() - 2]; 
        }
    } 
    vector<int> ans;
    rep(i, n)
    {
        int index = lower_bound(cc, cc + n, c[i]) - cc;
        if(bordera[index] <= a[i]) ans.push_back(i + 1); 
    }
    cout << ans.size() << endl;
    rep(i, ans.size()- 1)
    {
        cout << ans[i] << ' ';
    }
    cout << ans[ans.size() - 1] << endl;
    return 0;
}