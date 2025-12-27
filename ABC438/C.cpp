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
    //愚直に消して良い
    //余った場合、それを利用して消せるようにはならない
    //最後が消えたとしてもその前が消えるようになることはない
    int n;
    cin >> n;
    int a[n];
    int ans = n;
    rep(i, n) cin >> a[i];
    vector<pint> ran_len;
    int cnt = 1;
    int num = a[0];
    rep2(i, n - 1)
    {
        if (a[i] == num)
        {
            cnt++;
        }
        else
        {
            ran_len.push_back({num, cnt});
            num = a[i];
            cnt = 1;
        }
    }
    ran_len.push_back({num, cnt});
    stack<pint> back;
    rep(i, ran_len.size())
    {
        if (ran_len[i].second >= 4)
        {
            ans -= ran_len[i].second / 4 * 4;
            if (ran_len[i].second % 4 == 0)
            {
                if (!back.empty())
                {
                    pint tmp = back.top();
                    if (i != ran_len.size() - 1)
                    {
                        if (tmp.first == ran_len[i + 1].first)
                        {
                            ran_len[i + 1].second += tmp.second;
                            back.pop();
                        }
                    }
                }
            }
            else
            {
                back.push({ran_len[i].first, (ran_len[i].second - (ran_len[i].second / 4 * 4))});
            }
        }
        else
        {
            back.push({ran_len[i].first, ran_len[i].second});
        }
    }
    cout << ans << endl;
    return 0;
}
