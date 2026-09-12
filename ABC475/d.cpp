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
    string s;
    cin >> s;
    vector<int> p;
    vector<bool> is_p(10000000, true);
    is_p[0] = false;
    is_p[1] = false;
    for (int i = 2; i <= 10000000; i++)
    {
        if (is_p[i])
        {
            for (int j = 2 * i; j<= 10000000; j += i)
            {
                is_p[j] = false;
            }
            p.push_back(i);
        }
    }
    int start = 1;
    rep(i, s.size() - 1) start *= 10;
    int last = start * 10 - 1;
    int s_index = lower_bound(p.begin(), p.end(), start) - p.begin();
    for (int i = s_index; p[i] <= last && i < p.size(); i++)
    {
        string num_s = to_string(p[i]);
        bool ok = true;
        vector<int> dist(26, -1);
        vector<bool> dist_num(10, false);
        rep(j, num_s.size())
        {
            if (dist[s[j] - 'a'] == -1)
            {
                dist[s[j] - 'a'] = (num_s[j] - '0');
                if (dist_num[num_s[j] - '0'])
                {
                    ok = false;
                    break;
                }
                dist_num[num_s[j] - '0'] = true;
            }
            else
            {
                if (dist[s[j] - 'a'] != (num_s[j] - '0'))
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
        {
            cout << num_s << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
