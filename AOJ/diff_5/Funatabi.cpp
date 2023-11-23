#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2e8;
const long long l_inf = 9223372036854775807;
int main()
{
    //各命令について全航路を更新しても十分間に合う
    //a,bを更新するとき新しい航路を使うルートはa->c->d->bかa->d->c->b
    //上の方法でやればa==c, b==dのパターンもfare[a][c]やfare[b][d]は0なので大丈夫
    int n,k;
    cin >> n >> k;
    int fare[n][n];
    vector<int> ans;
    rep(i,n) rep(j,n)
    {
        if(i == j) fare[i][j] = 0;
        else fare[i][j] = inf;
    }
    rep(i,k)
    {
        int kind,a,b,c;
        cin >> kind >> a >> b;
        a--; b--;
        if(kind == 0)
        {
            if(fare[a][b] >= inf) ans.push_back(-1);
            else ans.push_back(fare[a][b]);
        }
        if(kind == 1)
        {
            cin >> c;
            rep(j,n)
            {
                rep(l,n)
                {
                    int tmp_1 = 0,tmp_2 = 0;
                    //j->a->b->l
                    tmp_1 = fare[j][a] + c + fare[b][l];
                    //j->b->a->l
                    tmp_2 = fare[j][b] + c + fare[a][l];
                    fare[j][l] = min(min(fare[j][l], tmp_1), tmp_2);
                }
            }
        } 
    }
    rep(i,ans.size()) cout << ans[i] << endl;
    return 0;
}