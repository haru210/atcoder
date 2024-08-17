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

int main()
{
    int h, w;
    cin >> h >> w;
    int ni, nj;
    cin >> ni >> nj;
    ni--;
    nj--;
    string s[h];
    rep(i, h) cin >> s[i];
    string mv;
    cin >> mv;
    rep(i, mv.size())
    {
        int ii = ni;
        int jj = nj;
        if(mv[i] == 'U') ii--;
        if(mv[i] == 'D') ii++;
        if(mv[i] == 'L') jj--;
        if(mv[i] == 'R') jj++;
        if(ii < 0 || ii >= h || jj < 0 || jj >= w) continue;
        if(s[ii][jj] == '#') continue;
        ni = ii;
        nj = jj;
    } 
    cout << ni + 1 << ' ' << nj + 1 << "\n";
    return 0;
}