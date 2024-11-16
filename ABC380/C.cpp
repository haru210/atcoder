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
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<pair<char, int>> rl;
    char nc = 'a';
    int nl = 0; 
    rep(i, n)
    {
        if(nc != s[i])
        {
            if(i != 0)rl.push_back(make_pair(nc, nl));
            nl = 1;
            nc = s[i];
        }
        else
        {
            nl++;
        }
    }
    rl.push_back(make_pair(nc,nl));
    int cnt1 = 0;
    rep(i, rl.size())
    {
        if(rl[i].first == '1')
        {
            cnt1++;
        }
        rep(j, rl[i].second)
        {
            cout << rl[i].first;
        }
        if(cnt1 == k - 1)
        {
            rep(j, rl[i + 2].second)
            {
                cout << rl[i + 2].first;
            }
            rep(j, rl[i + 1].second)
            {
                cout << rl[i + 1].first;
            }
            cnt1++;
            i += 2;
        }
    }
    return 0;
}