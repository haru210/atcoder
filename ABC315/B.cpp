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
    int m;
    cin >> m;
    int day[m];
    int day_sum = 0;
    int center;
    rep(i,m) 
    {
        cin >> day[i];
        day_sum += day[i];
    }
    center = (day_sum+1) / 2;
    int prev_day = 0;
    int day_cnt = 0;
    rep(i,m)
    {
        day_cnt += day[i];
        if(day_cnt >= center)
        {
            cout << i + 1 << ' ';
            break;
        }
        prev_day = day_cnt;
    }
    cout << center - prev_day << endl;
    return 0;
}