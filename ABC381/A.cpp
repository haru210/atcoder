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
    bool ok = true;
    if(n % 2 == 0) ok = false;
    rep(i, n / 2)
    {
        if(s[i] != '1') ok = false;
    }
    if(s[n / 2] != '/') ok = false;
    for(int i = (n / 2) + 1; i < n; i++)
    {
        if(s[i] != '2') ok = false;
    }
    YesNo(ok);
    return 0;
}