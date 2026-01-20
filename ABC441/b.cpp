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
    int n, m, q;
    string s;
    string t;
    set<char> t_dic;
    set<char> a_dic;
    cin >> n >> m >> s >> t >> q;
    rep(i, s.size())
    {
        t_dic.insert(s[i]);
    }
    rep(i, t.size())
    {
        a_dic.insert(t[i]);
    }
    rep(i, q)
    {
        string w;
        cin >> w;
        bool ended = false;
        rep(i, w.size())
        {
            if (t_dic.find(w[i]) == t_dic.end())
            {
                cout << "Aoki\n";
                ended = true;
                break;
            }
            else if (a_dic.find(w[i]) == a_dic.end())
            {
                cout << "Takahashi\n";
                ended = true;
                break;
            }
        }
        if (!ended) cout << "Unknown\n";
    }
    return 0;
}
