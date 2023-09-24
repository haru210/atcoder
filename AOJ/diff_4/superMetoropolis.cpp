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
    int w,h,n;
    cin >> w >> h >> n;
    pint spot[n];
    rep(i,n) cin >> spot[i].first >> spot[i].second;
    ll ans = 0;
    int x = spot[0].first;
    int y = spot[0].second;
    rep2(i,n-1)
    {
        while(true)
        {
            if(x == spot[i].first && y == spot[i].second) break;
            if(x == spot[i].first)
            {
                ans += abs(spot[i].second - y);
                y = spot[i].second;
                break;
            }
            else if(y == spot[i].second)
            {
                ans += abs(spot[i].first - x);
                x = spot[i].first;
                break;
            }
            else
            {
                //斜め移動したほうがいい時
                if((x < spot[i].first && y < spot[i].second) || (x > spot[i].first && y > spot[i].second))
                {
                    if(x < spot[i].first)
                    {
                        x++;
                        y++;
                        ans++;
                    }
                    if(x > spot[i].first)
                    {
                        x--;
                        y--;
                        ans++;
                    } 
                }
                //しないほうがいい時
                else
                {
                    if(x < spot[i].first)
                    {
                        x++;
                        ans++;
                    }
                    if(x > spot[i].first)
                    {
                        x--;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}