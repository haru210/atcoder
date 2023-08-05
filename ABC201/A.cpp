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
    int a[3];
    rep(i,3) cin >> a[i];
    sort(a,a+3);
    if(a[1]-a[0] == a[2] - a[1]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}