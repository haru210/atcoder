#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int x,y;
    bool ans = false;
    cin >> x >> y;
    if(x > y)
    {
        if(x - y <= 3) ans = true; 
    }
    if(x < y)
    {
        if(y - x <= 2) ans = true;
    }
    YesNo(ans);
    return 0;
}