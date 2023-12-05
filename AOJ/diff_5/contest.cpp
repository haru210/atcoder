#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int n,m,t,x,y;
    cin >> n >> m >> t >> x >> y;
    int p[m];
    int started[n][m] = {};
    int w_cnt[n][m] = {};
    ll score[n] = {};
    rep(i,m) cin >> p[i];
    rep(i,y)
    {
        int time,user,ques;
        string result;
        cin >> time >> user >> ques >> result;
        user--; ques--;
        if(result == "open")
        {
            started[user][ques] = time;
        }
        if(result == "incorrect")
        {
            w_cnt[user][ques]++;
        }
        if(result == "correct")
        {
            score[user] += max(p[ques] - (time - started[user][ques]) - 120 * w_cnt[user][ques], x);
        }
    }
    rep(i,n) cout << score[i] << endl;
    return 0;
}