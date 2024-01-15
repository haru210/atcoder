#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    ll n;
    string s = "";
    cin >> n;
    if(n == 1) s += '0';
    n--; //0を含めるために1を引く
    while(n > 0)
    {
        int tmp = n % 5;
        tmp *= 2;
        s += to_string(tmp);
        n /= 5;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}