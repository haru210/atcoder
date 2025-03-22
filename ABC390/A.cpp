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
    int a[5];
    bool ans = false;
    rep(i, 5) cin >> a[i];
    rep(i, 4)
    {
        int tmp[5];
        rep(j, 5)
        {
            tmp[j] = a[j];
        }
        swap(tmp[i], tmp[i + 1]);
        bool ok = true;
        rep(j, 5)
        {
            if(j + 1 != tmp[j]) ok = false;
        }
        if(ok) ans = true;
    }
    YesNo(ans);
    return 0;
}