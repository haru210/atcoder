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
    int n,k;
    cin >> n >> k;
    rep(i,k)
    {
        int a,b;
        cin >> a >> b;
        int l,r,u,d;
        l = a;
        r = n - a + 1;
        u = b;
        d = n - b + 1;
        int tmp = min(l,r);
        int tmp2 = min(u,d);
        int mark = min(tmp,tmp2);
        mark %= 3;
        if(mark == 0) cout << 3 << endl;
        else cout << mark << endl;
    }
    return 0;
}