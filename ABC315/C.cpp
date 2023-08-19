#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    pair<ll,ll> cup[n];
    bool key = false;
    rep(i,n)
    {
        cin >> cup[i].second >> cup[i].first;
    }
    sort(cup,cup + n,greater<pair<ll,ll>>());
    ll max_satisfied = cup[0].first + (cup[1].first / 2);
    if(cup[0].second != cup[1].second)
    {
        cout << cup[0].first + cup[1].first << endl;
        key = true;
    }
    else
    {
        for(int i = 2; i < n; i++)
        {
            if(cup[0].second != cup[i].second)
            {
                max_satisfied = max(max_satisfied,cup[0].first + cup[i].first);
                cout << max_satisfied << endl;
                key = true;
                break;
            }
        }
    }
    if(!key) cout << max_satisfied << endl;
    return 0;
}