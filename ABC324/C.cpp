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
    string t;
    int cnt = 0;
    cin >> n >> t;
    string s[n];
    vector<int> ans;
    rep(i,n) cin >> s[i];
    rep(i,n)
    {
        bool ok = true;
        //文字数が同じならt=t'または一文字変更→違う文字をカウント
        if(s[i].size() == t.size())
        {
            int tmp = 0;
            rep(j,t.size())
            {
                if(s[i][j] != t[j]) tmp++;
                if(tmp >= 2)
                {
                    ok = false;
                    break;
                }
            }
        }
        //sのほうが短いとき
        //違ったらt文字側の探索を一文字止める
        //それが二回起きたら違う
        else if(s[i].size()+1 == t.size())
        {
            bool isSkip = false;
            int s_num = -1;
            rep(t_num,t.size())
            {
                s_num++;
                if(s[i][s_num] != t[t_num] && !isSkip)
                {
                    s_num--;
                    isSkip = true;               
                }
                else if(s[i][s_num] != t[t_num] && isSkip)
                {
                    ok = false;
                    break;
                }
            }
        }
        else if(s[i].size()-1 == t.size())
        {
            bool isSkip = false;
            int s_num = -1;
            rep(t_num,t.size())
            {
                s_num++;
                if(s[i][s_num] != t[t_num] && !isSkip)
                {
                    t_num--;
                    isSkip = true;               
                }
                else if(s[i][s_num] != t[t_num] && isSkip)
                {
                    ok = false;
                    break;
                }
            }

        }
        //2文字以上違うときはありえない
        else
        {
            ok = false;
        }
        if(ok) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()-1)
    {
        cout << ans[i] << ' '; 
    }
    if(ans.size() != 0)cout << ans[ans.size()-1] << endl;
    else cout << endl;
    return 0;
}