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
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    ll give_cnt[n + 1] = {};
    ll most_stone[n] = {}; //それぞれが石を貰うタイミングでの石の数
    rep(i, n)
    {
        most_stone[i] = a[i];
    }
    rep(i, n)
    {
        most_stone[i] += give_cnt[i];
        give_cnt[i + 1] += give_cnt[i] + 1;
        if(most_stone[i] < (n - i - 1))
        {
            give_cnt[i + 1 + most_stone[i]]--;
        }
    }
    rep(i, n)
    {
        int tmp = most_stone[i] - (n - i - 1);
        if(tmp < 0) tmp = 0;
        cout << tmp;
        if(i != n - 1) cout << ' ';
        else cout << endl;
    }
    return 0;
}