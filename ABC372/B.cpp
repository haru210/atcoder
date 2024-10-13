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
    int m;
    vector<int> ans;
    int n = 0;
    cin >> m;
    while(m >= 3)
    {
        ans.push_back(m % 3);
        n += m % 3;
        m /= 3;
    }
    ans.push_back(m);
    n += m;
    cout << n << endl;
    rep(i, ans.size())
    {
        rep(j, ans[i])
        {
            cout << i << ' ';
        }
    }
    return 0;
}