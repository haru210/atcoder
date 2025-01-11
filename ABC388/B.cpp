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
    int n, d;
    cin >> n >> d;
    int th[n], lo[n];
    rep(i, n)
    {
        cin >> th[i] >> lo[i];
    }
    rep2(i, d)
    {
        int max_weight = -1;
        rep(j, n)
        {
            int tmp = th[j] * (lo[j] + i);
            max_weight = max(max_weight, tmp);
        }
        cout << max_weight << endl;
    }
    return 0;
}