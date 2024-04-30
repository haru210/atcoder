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
    string s;
    cin >> s;
    ll al = ((ll)s.size() * ((ll)s.size()-1)) / 2;
    string s_cp = s;
    sort(s_cp.begin(), s_cp.end());
    vector<ll> dup;
    rep(i,s_cp.size())
    {
        if(i == 0)
        {
            dup.push_back(1);
        }
        else
        {
            if(s_cp[i] == s_cp[i-1])
            {
                dup[dup.size()-1]++;
            }
            else
            {
                dup.push_back(1);
            }
        }
    }
    ll unchanged = 0;
    rep(i,dup.size())
    {
        unchanged += ((dup[i] * (dup[i] - 1)) / 2);
    }
    if(unchanged == 0) cout << al << endl;
    else cout << al - (unchanged - 1) << endl;
    return 0;
}