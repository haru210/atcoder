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

//色の切り替わるところにedgeを置き、変換ごとに左右のedgeを二分探索
//奇数個目のedgeは白→黒(a[-1]は白とする)、偶数個目は黒→白
int main()
{
    int n, q;
    cin >> n >> q;
    int a[q];
    rep(i, q) 
    {
        cin >> a[i];
        a[i]--;
    }
    bool is_black[n] = {};
    int ans = 0;
    rep(i, q)
    {
        if(!is_black[a[i]])
        {
            int cnt = 0;
            is_black[a[i]] = true;
            if(a[i] != 0)
            {
                if(is_black[a[i] - 1])
                {
                    cnt++;
                }
            }
            if(a[i] != n - 1)
            {
                if(is_black[a[i] + 1])
                {
                    cnt++;
                }
            }
            if(cnt == 0) ans++;
            if(cnt == 2) ans--;
        }
        else
        {
            int cnt = 0;
            is_black[a[i]] = false;
            if(a[i] != 0)
            {
                if(is_black[a[i] - 1])
                {
                    cnt++;
                }
            }
            if(a[i] != n - 1)
            {
                if(is_black[a[i] + 1])
                {
                    cnt++;
                }
            }
            if(cnt == 0) ans--;
            if(cnt == 2) ans++;
        }
        cout << ans << endl;
    } 
    return 0;
}