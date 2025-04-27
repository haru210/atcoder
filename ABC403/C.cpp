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
    int n, m, q;
    cin >> n >> m >> q;
    set<int> perm[n];
    bool all_perm[n] = {};
    rep(i, q)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            perm[x].insert(y);
        }
        if(query == 2)
        {
            int x;
            cin >> x;
            x--;
            all_perm[x] = true;
        }
        if(query == 3)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(all_perm[x]) cout << "Yes\n";
            else if(perm[x].find(y) != perm[x].end()) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}