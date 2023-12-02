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
    int n,s,m,l;
    int ans = inf;
    cin >> n >> s >> m >> l;
    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 17; j++)
        {
            for(int k = 0; k < 17; k++)
            {
                int sum = i * 6 + j * 8 + k * 12;
                int price = s * i + m * j + k * l;
                if(sum >= n) ans = min(ans, price);
            }
        }
    }
    cout << ans << endl;
    return 0;
}