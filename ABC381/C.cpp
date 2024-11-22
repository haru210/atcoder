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
    int n;
    string s;
    cin >> n >> s;
    char nc = 'a';
    int nl = 0;
    vector<pair<char, int>> runLen;
    vector<int> slash_point;
    rep(i, n)
    {
        if(s[i] != nc)
        {
            if(i != 0)
            {
                runLen.push_back({nc, nl});
                if(nc = '/')
                {
                    slash_point.push_back(runLen.size() - 1);
                }
            }
                nl = 1;
                nc = s[i];
        }
        else
        {
            nl++;
        }
    }
    runLen.push_back({nc, nl});
    int ans = 1;
    for(auto& i: slash_point)
    {
        if(i == 0 || i == n - 1) continue;
        if(runLen[i - 1].first == '1' && runLen[i + 1].first == '2')
        {
            ans = max(ans, min(runLen[i - 1].second, runLen[i + 1].second) * 2 + 1);
        }
    }
    cout << ans << endl;
    return 0;
}