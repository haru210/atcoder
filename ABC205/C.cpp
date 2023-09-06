#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//a>0 && b>0なら大きいほう
//a<0 && b<0ならcが偶数で大きいほう、奇数で小さいほう
// aかbだけが<0なら偶数で>0な方、奇数なら絶対値が大きいほう
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a >= 0 && b >= 0)
    {        
    }
    else if(a < 0 && b < 0)
    {
        if(c %2 == 1)
        {
            a *= -1;
            b *= -1;
        }
    }
    else
    {
        if(c %2 == 0)
        {
            a = abs(a);
            b = abs(b);
        }
        else
        {
            if(a < 0) a = -1 * inf;
            if(b < 0) b = -1 * inf;
        }
    }
    if(a > b) cout << ">\n";
    else if(a < b) cout << "<\n";
    else cout << "=\n";
    return 0;
}