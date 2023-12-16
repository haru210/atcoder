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
    char s1,s2,t1,t2;
    bool ok = false;
    cin >> s1 >> s2 >> t1 >> t2;
    int s1_n = s1 - 'A';
    int s2_n = s2 - 'A';
    int t1_n = t1 - 'A';
    int t2_n = t2 - 'A';
    bool s_near = false;
    bool t_near = false;
    if((abs(s1_n - s2_n) % 3) == 1)s_near = true;
    if((abs(t1_n - t2_n) % 3) == 1)t_near = true;
    if(s_near == t_near) ok = true;
    YesNo(ok);
    return 0;
}