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
    int n;
    cin >> n;
    bool buried[n+1][n+1] = {};
    int num[n][n] = {};
    int dir = 1; //1,2,3,4 = 右下左上
    int x = 0,  y = 0;
    num[y][x] = 1;
    buried[y][x] = true;
    //まっすぐ進む->前が埋まってたら右に曲がる
    rep2(i, n * n - 2)
    {
        int n_x = x, n_y = y;
        if(dir == 1) n_x++;
        if(dir == 2) n_y++;
        if(dir == 3) n_x--;
        if(dir == 4) n_y--;
        if(n_x < 0 || n_x >= n || n_y < 0 || n_y >= n)
        {
            if(dir != 4) dir++;
            else dir = 1;
            i--;
            continue;
        }
        else if(buried[n_y][n_x])
        {
            if(dir != 4) dir++;
            else dir = 1;
            i--;
            continue;
        }
        num[n_y][n_x] = i+1;
        buried[n_y][n_x] = true;
        x = n_x;
        y = n_y;
    }
    rep(i,n)
    {
        rep(j,n)
        {
            if(num[i][j] == 0) cout << 'T' << ' ';
            else cout << num[i][j] << ' ';
        }
        if(i != n-1)cout << endl;
    }
    return 0;
}