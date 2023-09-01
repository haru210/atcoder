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
    int sum = 0;
    cin >> n;
    int a[n];
    rep(i,n)
    {
        cin >> a[i];
    }
    rep(i,n)
    {
        if(a[i] > 10) sum += a[i] - 10;
    }
    cout << sum << endl;
    return 0;
}