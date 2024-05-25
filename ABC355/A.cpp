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
     int a, b;
     cin >> a >> b;
     if(a == b) cout << -1 << endl;
     else
     {
        bool one = true;
        bool two = true;
        bool three = true;
        if(a == 1 || b == 1) one = false;
        if(a == 2 || b == 2) two = false;
        if(a == 3 || b == 3) three = false;
        if(one) cout << 1 << endl;
        else if(two) cout << 2 << endl;
        else cout << 3 << endl; 
     }
    return 0;
}