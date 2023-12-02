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
char ans[5][5];

int line[5] = {0}; //行
int column[5] = {0}; //列

int dfs(int x, int y);
void judge();

int n;
string r,c;
bool outed = false;
int main()
{

    //A,B,Cが出たかをbit列で管理
    //1ビット目から順にABC
    cin >> n >> r >> c;
    rep(i,n) rep(j,n) ans[i][j] = '.';
    //各行、各列で出たアルファベットをbit列で管理
    //各マスに入れられるアルファベットを全探索
    //条件を満たすかは管理したbit列がすべて111であれば、あとはO(N^2)
    //全探索の方法->dfsでやってみる
    //今調べている座標をdfsの情報としてx,yで持つ
    dfs(0,0);
    if(!outed) cout << "No\n";
    return 0;
}
int dfs(int x, int y)
{
    bool isA = true, isB = true, isC = true;
    if(line[y] == 0)
    {
        if(r[y] == 'A')
        {
            isB = false;
            isC = false;
        }
        if(r[y] == 'B')
        {
            isA = false;
            isC = false;
        }
        if(r[y] == 'C')
        {
            isA = false;
            isB = false;
        }
    }
    if(column[x] == 0)
    {
        if(c[x] == 'A')
        {
            isB = false;
            isC = false;
        }
        if(c[x] == 'B')
        {
            isA = false;
            isC = false;
        }
        if(c[x] == 'C')
        {
            isA = false;
            isB = false;
        }

    }
    //Aに出来るか
    if(((line[y] & 1) == 0) && ((column[x] & 1) == 0) && isA)
    {
        ans[y][x] = 'A';
        line[y] |= 1; column[x] |= 1;
        if(x == n - 1 && y == n - 1) judge();
        else if(x == n-1) dfs(0, y+1);
        else dfs(x+1, y);
        line[y] &= ~1; column[x] &= ~1;
    }
    if(outed)
    {
        return 0;
    } 
    if(((line[y] & 2) == 0) && ((column[x] & 2) == 0) && isB)
    {
        ans[y][x] = 'B';
        line[y] |= 2; column[x] |= 2;
        if(x == n - 1 && y == n - 1) judge();
        else if(x == n-1) dfs(0, y+1);
        else dfs(x+1, y);
        line[y] &= ~2; column[x] &= ~2;
    }
    if(outed)
    {
        return 0;
    } 
    if(((line[y] & 4) == 0) && ((column[x] & 4) == 0) && isC)
    {
        ans[y][x] = 'C';
        line[y] |= 4; column[x] |= 4;
        if(x == n - 1 && y == n - 1) judge();
        else if(x == n-1) dfs(0, y+1);
        else dfs(x+1, y);
        line[y] &= ~4; column[x] &= ~4;
    }
    if(outed)
    {
        return 0;
    } 
    ans[y][x] = '.';
    if(x == n - 1 && y == n - 1) judge();
    else if(x == n-1) dfs(0, y+1);
    else dfs(x+1, y);
    if(outed)
    {
        return 0;
    }
    return 0;
}

void judge()
{
    bool ok_line = true;
    bool ok_column = true;
    rep(i,n)
    {
        if(line[i] != 7) ok_line = false;
        if(column[i] != 7) ok_column = false;
        if((!ok_line) && (!ok_column)) break;
    }
    if(ok_line && ok_column && !outed)
    {
        outed = true;
        cout << "Yes\n";
        rep(i,n)
        {
            rep(j,n)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}