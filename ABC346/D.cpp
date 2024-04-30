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

//二種累積和
//01or10がn個+同じ数字+10or01がn個の構成になるはず
//累積和の考えで残す位置ごとに必要なコストを計算できるのでは？
//2x10^5*10^9はll定期
int main()
{
    ll n;
    ll ans = l_inf;
    string s;
    cin >> n >> s;
    ll c[n+1];
    rep2(i,n) cin >> c[i];
    //累積和は1-indexedのほうが楽定期
    ll sum_01[n+1] = {};
    ll sum_10[n+1] = {};
    rep2(i,n)
    {
        sum_01[i] = sum_01[i-1];
        sum_10[i] = sum_10[i-1];
        if((i % 2) == 1)
        {
            //奇数文字目
            if(s[i-1] == '1')
            {
               // cout << i << endl;
                sum_01[i] += c[i];
            }
            if(s[i-1] == '0')
            {
                sum_10[i] += c[i];
            }
        }
        else
        {
            //偶数文字目
            if(s[i-1] == '1')
            {
                sum_10[i] += c[i];
            }
            if(s[i-1] == '0')
            {
                sum_01[i] += c[i];
            }
        }
    }
    //一致する場所iと、1にするか0にするかを全探索
    rep2(i,n-1)
    {
        ll tmp_0 = 0; //i=0
        ll tmp_1 = 0; //i=1
        //iが0の時->i-1を1にしたい
        //0~i-1が偶数なら01、0~i-1が奇数個なら10
        //前
        if((i - 1) % 2 == 0)
        {
            tmp_0 += sum_01[i-1];
        }
        else
        {
            tmp_0 += sum_10[i-1];
        }
        if(s[i-1] == '1') tmp_0 += c[i];
        //i+1を0にしたい
        if((i+1) % 2 == 0) tmp_0 += (sum_10[n] - sum_10[i]);
        else tmp_0 += (sum_01[n] - sum_01[i]);

        if((i - 1) % 2 == 0)
        {
            tmp_1 += sum_10[i-1];
        }
        else
        {
            tmp_1 += sum_01[i-1];
        }
        if(s[i-1] == '0') tmp_1 += c[i];
        if((i+1) % 2 == 0) tmp_1 += (sum_01[n] - sum_01[i]);
        else tmp_1 += (sum_10[n] - sum_10[i]);

        ans = min(ans, min(tmp_0, tmp_1));
    }
    cout << ans << endl;
    return 0;
}