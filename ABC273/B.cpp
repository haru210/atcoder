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
    ll x;
    int k;
    cin >> x >> k;
    rep(i, k)
    {
        x /= pow(10,i);
        if(x % 10 >= 5)
        {
            x += 10;
        }
        x -= x % 10;
        x *= pow(10,i);
    }
    cout << x << endl;
    return 0;
}

