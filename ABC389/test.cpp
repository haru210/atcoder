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
//シンプルな二次元dpは即死する

int main()
{
    ll num = 0;
    ll tmp = 1;
    while(num <= 1000000000000000000)
    {
        num += tmp * tmp;
        tmp++;
    }
    cout << tmp << endl;
    return 0;
}