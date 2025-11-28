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
    int cnt = 0;
    vector<char> text;
    set<int> bad;
    rep(i, q)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            char c;
            cin >> c;
            if(c == '(')
            {
                cnt++;
                text.push_back('(');
            }
            else
            {
                cnt--;
                text.push_back(')');
            }
            if(cnt < 0)
            {
                bad.insert(text.size() - 1);
            }
        }
        else
        {
            if(bad.find(text.size() - 1) != bad.end())
            {
                bad.erase(text.size() - 1);
            }
            if(text[text.size() - 1] == '(')
            {
                cnt--;
                text.pop_back();
            }
            else
            {
                cnt++;
                text.pop_back();
            }
        }
        if(bad.size() != 0) cout << "No\n";
        else if(cnt != 0) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}