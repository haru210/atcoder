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
    map<int, int> a;
    int var_3 = 0;
    int var_2 = 0;
    rep(i, 7)
    {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    for(auto& [key, val]: a)
    {
        if(val >= 3) var_3++;
        else if(val == 2) var_2++;
    }
    if(var_3 >= 2 || (var_3 >= 1 && var_2 >= 1))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}