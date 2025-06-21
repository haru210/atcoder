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
    //文字列のコピーはlength回コピーが必要なので10^6*10^5でTLEしそう
    //逆順にみて、3 pを探す->1 pを探す->3 pを探す...で見つけた2のsを足していく
    int n, q;
    cin >> n >> q;
    vector<pair<int, pair<int, string>>> ques(q); 
    rep(i, q)
    {
        int query;
        int p;
        string s = "";
        cin >> query >> p;
        if(query == 2)
        {
            cin >> s;
            reverse(s.begin(), s.end());
        }
        ques[i] = {query, {p, s}};
    }
    reverse(ques.begin(), ques.end());
    bool is_3 = false;
    int search_p = -1;
    string ans = "";
    rep(i, q)
    {
        if(!is_3 && ques[i].first == 3)
        {
            is_3 = true;
            search_p = ques[i].second.first;
        }
        if(is_3)
        {
            if(ques[i].first == 2 && ques[i].second.first == search_p)
            {
                //reverse(ques[i].second.second.begin(), ques[i].second.second.end());
                ans += ques[i].second.second;
            }
            if(ques[i].first == 1 && ques[i].second.first == search_p)
            {
                is_3 = false;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}