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
    //oか.にせざるをえないorどちらでもよいを判定する
    //oの隣の?は.なので、.(n個の?).の繰り返しのみを考えればよい
    int n, k;
    int o_cnt = 0;
    string s;
    string ans;
    vector<int> ques_rle;
    cin >> n >> k >> s;
    ans = s;
    rep(i, n)
    {
        if(i - 1 >= 0)
        {
            if(s[i] == '?' && s[i - 1] == 'o')
            {
                s[i] = '.';
                ans[i] = '.';
            }
        }
        if(i + 1 < n)
        {
            if(s[i] == '?' && s[i + 1] == 'o')
            {
                s[i] = '.';
                ans[i] = '.';
            }
        }
        if(s[i] == 'o') o_cnt++;
    }
    int cnt = 0;
    rep(i, n)
    {
        if(s[i] == '?')
        {
            cnt++;
        }
        else
        {
            if(cnt != 0)
            {
                ques_rle.push_back(cnt);
            }
            cnt = 0;
        }
        if(i == n - 1)
        {
            if(cnt != 0)
            {
                ques_rle.push_back(cnt);
            }
        }
    }
    int o_max = 0;
    rep(i, ques_rle.size())
    {
        o_max += (ques_rle[i] + 1) / 2;
    }
    if(k - o_cnt == 0)
    {
        rep(i, n) 
        {
            if(ans[i] == '?') ans[i] = '.';
        }
    }
    else if(o_max + o_cnt == k)
    {
        int rlei = 0;
        rep(i, n)
        {
            if(s[i] == '?')
            {
                if(ques_rle[rlei] % 2 == 0)
                {
                    i += ques_rle[rlei] - 1;
                    rlei++;
                }
                else 
                {
                    rep(j, ques_rle[rlei])
                    {
                        if(j % 2 == 0) ans[i + j] = 'o';
                        else ans[i + j] = '.';
                    }
                    i += ques_rle[rlei] - 1;
                    rlei++;
                }
            }
        }
    }

    rep(i, n)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}