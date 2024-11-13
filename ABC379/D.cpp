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
    int q;
    cin >> q;
    ll sum[q] = {}; //sum[n] := n個目のクエリで累積何日待ったか
    sum[0] = 0;
    queue<int> plants;
    rep2(i, q)
    {
        int var;
        cin >> var;
        int day = 0; //このクエリでの経過日数
        if(var == 1)
        {
            plants.push(i);
        }
        if(var == 2)
        {
            cin >> day;
        }
        if(var == 3)
        {
            ll tmp;
            cin >> tmp;
            ll ans = 0;
            while(!plants.empty())
            {
                int plant = plants.front();
                ll lplant = sum[i - 1] - sum[plant];
                if(lplant >= tmp)
                {
                    plants.pop();
                    ans++;
                }
                else
                {
                    break;
                }
            }
            cout << ans << endl;
        }
        sum[i] = sum[i - 1] + day;
    }
    return 0;
}