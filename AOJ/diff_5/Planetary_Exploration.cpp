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
    int m,n,k;
    cin >> m >> n >> k;
    char s[m+5][n+5];
    rep2(i,m) rep2(j,n) cin >> s[i][j];
    int sum_j[m+5][n+5] = {};
    int sum_o[m+5][n+5] = {};
    int sum_i[m+5][n+5] = {};
    rep2(i,m) rep2(j,n)
    {
        if(s[i][j] == 'J') sum_j[i][j] = sum_j[i][j-1] + 1;
        else sum_j[i][j] = sum_j[i][j-1];
        if(s[i][j] == 'O') sum_o[i][j] = sum_o[i][j-1] + 1;
        else sum_o[i][j] = sum_o[i][j-1];
        if(s[i][j] == 'I') sum_i[i][j] = sum_i[i][j-1] + 1;
        else sum_i[i][j] = sum_i[i][j-1];
    }
    rep2(j,n) rep2(i,m)
    {
        sum_j[i][j] += sum_j[i-1][j];
        sum_o[i][j] += sum_o[i-1][j];
        sum_i[i][j] += sum_i[i-1][j];
    }
    pint lu, rd;
    rep(i,k)
    {
        cin >> lu.first >> lu.second >> rd.first >> rd.second;
        cout << sum_j[rd.first][rd.second] - sum_j[rd.first][lu.second-1] - sum_j[lu.first-1][rd.second] + sum_j[lu.first-1][lu.second-1] << ' ';
        cout << sum_o[rd.first][rd.second] - sum_o[rd.first][lu.second-1] - sum_o[lu.first-1][rd.second] + sum_o[lu.first-1][lu.second-1] << ' ';
        cout << sum_i[rd.first][rd.second] - sum_i[rd.first][lu.second-1] - sum_i[lu.first-1][rd.second] + sum_i[lu.first-1][lu.second-1] << endl;
    }
    return 0;
}