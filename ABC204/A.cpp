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
    int x,y;
    cin >> x >> y;
    if(x == y) cout << x << endl;
    else
    {
        bool g=false,c=false,p=false;
        if(x == 0 || y == 0) g=true;
        if(x == 1 || y == 1) c=true;
        if(x == 2 || y == 2) p=true;
        if(!g) cout << 0 << endl;
        if(!c) cout << 1 << endl;
        if(!p) cout << 2 << endl;
    }
    return 0;
}