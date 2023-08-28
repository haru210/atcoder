#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
char s[500][500];
char t[500][500];
char s_r[500][500];
char s_l[500][500];
char s_u[500][500];
int main()
{
    int n;
    int cnt;
    int nr=0,l=0,r=0,u=0;
    cin >> n;
    rep(i,n) rep(j,n)
    {
        cin >> s[i][j];
    }
    rep(i,n) rep(j,n)
    {
        cin >> t[i][j];
    }
    //各回転作り
    rep(i,n) rep(j,n)
    {
        s_l[i][j] = s[j][n-1-i];
        s_r[i][j] = s[n-1-j][i];
    }
    rep(i,n) rep(j,n)
    {
        s_u[i][j] = s_l[j][n-1-i];
    }
    rep(i,n) rep(j,n)
    {
        if(s_l[i][j] != t[i][j]) l++;
        if(s_r[i][j] != t[i][j]) r++;
        if(s_u[i][j] != t[i][j]) u++;
        if(s[i][j] != t[i][j]) nr++;
    }
    cout << endl;
    l++; r++; u+=2;
    cnt = min(l,r);
    cnt = min(cnt,u);
    cnt = min(cnt,nr);
    cout << cnt << endl;
    return 0;
}