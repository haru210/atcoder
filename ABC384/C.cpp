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

bool comp(pair<int, string> p1, pair<int, string> p2)
{
    if(p1.first != p2.first) return p1.first > p2.first;
    else return p1.second < p2.second;
}

int main()
{
    int score[5] = {};
    rep(i, 5) cin >> score[i];
    vector<pair<int, string>> ans;
    //最上位桁から順にabcdeを割り当てる
    for(int i = 0; i < (1 << 5); i++)
    {
        if(i == 0) continue; 
        string name = "";
        int sc = 0;
        rep(j, 5)
        {
            if(i & (1 << j))
            {
                sc += score[j];
                name += 'A' + j;
            }
        }
        ans.push_back({sc, name});
    }    
    sort(ans.begin(), ans.end(), comp);
    rep(i, ans.size())
    {
        cout << ans[i].second << endl;
    }
    return 0;
}