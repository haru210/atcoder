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
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    int d[n];
    rep(i,n) cin >> d[i];
    sort(d,d+n, greater<int>());
    int price = a;
    int cal = c;
    long double num = (long double)cal / (long double)price; 
    rep(i,n)
    {
        price += b;
        cal += d[i];
        long double tmp = (long double)cal / (long double)price;
        if(tmp > num) num = tmp;
        else break;
    }
    cout << (int)num << endl;
    return 0;
}