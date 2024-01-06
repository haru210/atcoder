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
    int n,q;
    cin >> n >> q;
    vector<pint> load;
    for(int i = n; i >= 1; i--)
    {
        load.push_back({i, 0});
    }
    rep(i,q)
    {
        int a, p;
        char b;
        cin >> a;
        int last_l = load.size() - 1;
        if(a == 1)
        {
            cin >> b;
            if(b == 'R')
            {
                load.push_back({load[last_l].first + 1, load[last_l].second});
            }
            if(b == 'L')
            {
                load.push_back({load[last_l].first - 1, load[last_l].second});
            }
            if(b == 'U')
            {
                load.push_back({load[last_l].first, load[last_l].second + 1});
            }
            if(b == 'D')
            {
                load.push_back({load[last_l].first, load[last_l].second - 1});
            }
        }
        if(a == 2)
        {
            cin >> p;
            cout << load[last_l - (p - 1)].first << ' ' << load[last_l - (p-1)].second << endl;
        }
    } 
    return 0;
}