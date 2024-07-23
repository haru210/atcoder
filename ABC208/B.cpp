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
    ll coin[11];
    ll p;
    cin >> p;
    coin[1] = 1;
    for(int i = 2; i <= 10; i++)
    {
        coin[i] = coin[i - 1] * i;
    }
    int cnt = 0;
    for(int i = 10; i >= 1; i--)
    {
        if(p >= coin[i])
        {
            while(p >= coin[i])
            {
                p -= coin[i];
                cnt++;
                if(p == 0) break;
            }
            if(p == 0) break;
        }
    }
    cout << cnt << "\n";
    return 0;
}