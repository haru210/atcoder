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
    bool ok = true;
    cin >> n;
    int t[n], x[n];
    map<int, int> pot;
    map<int,int> p_need;
    vector<vector<int>> pick(n+1);
    rep(i,n)
    {
        cin >> t[i] >> x[i];
    }
    //全部拾って余った数=個数
    rep(i,n)
    {
        if(t[i] == 1)
        {
            pot[x[i]] += 1;
            pick[x[i]].push_back(i);
        }
        if(t[i] == 2)
        {
            if(pot[x[i]] == 0)
            {
                ok = false;
            }
            else
            {
                pot[x[i]]--;
                p_need[x[i]]++;
            }
        }
    }
    int leftover = 0;
    return 0;
}