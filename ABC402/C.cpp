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
    //Bを先に見ておいて、各料理ごとに材料を見ていって、最後に食べれるようになる食材を見ればいつ食べれるか分かる
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    int b[n];
    int rel_food[n] = {};
    int rel_dish[n] = {};
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int tmp;
            cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }
    rep(i, n)
    {
        cin >> b[i];
        b[i]--;
        rel_food[b[i]] = i;
    }
    rep(i, m)
    {
        int least = -1;
        rep(j, a[i].size())
        {
            least = max(least, rel_food[a[i][j]]);
        }
        rel_dish[least]++;
    }
    int edible = 0;
    rep(i, n)
    {
        edible += rel_dish[i];
        cout << edible << endl;
    }
    return 0;
}