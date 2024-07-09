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
//貪欲に置ける時に置く
int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = ((w + 1) / 2) * ((h + 1) / 2);
    if(w == 1) cout << h << endl;
    else if(h == 1) cout << w << endl;
    else cout << cnt << endl;
    return 0;
}