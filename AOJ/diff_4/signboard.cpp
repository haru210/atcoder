#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int ans = 0;
    string s;
    cin >> n >> s;
    string board[n];
    rep(i,n)
    {
        cin >> board[i];
    }
    rep(i,n)
    {
        bool ok = false;
        vector<int> first;
        rep(j,board[i].size())
        {
            //1文字目の選択肢を全探索、1文字見つけたら何文字間隔か考える
            if(board[i][j] == s[0]) first.push_back(j);
        }
        rep(j,first.size())
        {
            for(int k = 1; (k * 2 + 1) + first[j] <= board[i].size(); k++)
            {
                bool ng = false;
                int l = first[j];
                for(int cnt = 0; cnt < s.size();cnt++)
                {
                    if(s[cnt] != board[i][l]) ng = true;
                    l += k;
                }
                if(!ng)
                {
                    ans++;
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
    }
    cout << ans << endl;
    return 0;
}