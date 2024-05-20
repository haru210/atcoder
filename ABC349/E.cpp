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
vector<vector<ll>> a(3, vector<ll>(3));
//盤面-> 0白, 1赤, 2青
//dfs ->その盤面で渡されたときそのプレイヤーが勝てるか(最終盤面はもう手番がないので関数は開かない)  
//win ->その盤面が終了しているか、終了している場合はどちらが勝利しているか 1->高橋 2->青木 0->未確定
ll win(vector<vector<ll>> b)
{
    bool ao = false;
    bool ta = false;
    bool end = false; //判定終了の意、ラインが完成しているor9マス埋まっていない時
    rep(i, 3)
    {
            if((b[i][0] == 1 && b[i][1] == 1) && b[i][2] == 1) {ta = true; end = true;}
            if((b[0][i] == 1 && b[1][i] == 1) && b[2][i] == 1) {ta = true; end = true;}
            if((b[i][0] == 2 && b[i][1] == 2) && b[i][2] == 2) {ao = true; end = true;}
            if((b[0][i] == 2 && b[1][i] == 2) && b[2][i] == 2) {ao = true; end = true;}
    }
    if(((b[0][0] == b[1][1]) &&(b[0][0] == b[2][2])) || ((b[0][2] == b[1][1]) && (b[0][2] == b[2][0])))
    {
        if(b[1][1] == 1) {ta = true; end = true;}
        if(b[1][1] == 2) {ao = true; end = true;}
    }
    rep(i, 3)
    {
        rep(j, 3)
        {
            if(b[i][j] == 0) end = true;
        }
    }
    if(!end)
    {
        ll tsc = 0;
        ll asc = 0;
        rep(i, 3)
        {
            rep(j, 3)
            {
                if(b[i][j] == 1) tsc += a[i][j];
                else if(b[i][j] == 2) asc += a[i][j];
            }
        }
        if(tsc > asc) ta = true;
        if(asc > tsc) ao = true;
    }
    if(ta) return 1;
    else if(ao) return 2;
    else return 0;
}
bool dfs(int turn, vector<vector<ll>> b)
{
    int nturn;
    bool ws = false;
    if(turn == 1) nturn = 2;
    else nturn = 1;
    //派生する盤面どれかで勝てるなら好きな盤面を選べるので勝ち
    rep(i, 3)
    {
        rep(j, 3)
        {
                vector<vector<ll>> cp = b;
                if(b[i][j] == 0)
                {
                    cp[i][j] = turn;
                    int result = win(cp);
                    if(result == 0) if(!(dfs(nturn, cp))) ws = true;
                    if(result == turn) ws = true;
                }
        }
    }
    return ws;
}
int main()
{
    rep(i, 3) rep(j, 3) cin >> a[i][j];
    vector<vector<ll>> board(3, vector<ll>(3, 0));
    bool takahashi = dfs(1, board);
    if(takahashi) cout << "Takahashi\n";
    else cout << "Aoki\n";
    return 0;
}