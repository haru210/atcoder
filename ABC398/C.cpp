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
    cin >> n;
    int a[n];
    rep(i, n)
    {
        cin >> a[i];
    }
    map<int, int> p;
    rep(i, n)
    {
        p[a[i]]++;
    }
    int ans_val = -1;
    for(auto& [key, val] : p)
    {
        if(val == 1)
        {
            ans_val = max(ans_val, key);
        }
    }
    if(ans_val == -1) cout << -1 << endl;
    else
    {
        rep(i, n)
        {
            if(a[i] == ans_val) cout << i + 1 << endl;
        }
    }
    return 0;
}