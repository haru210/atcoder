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
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    set<pint> tar;
    tar.insert({r, c});
    int ni = 0;
    int nj = 0;
    int tari = r;
    int tarj = c;
    ll ans = 0;
    rep(i, n)
    {
        if(s[i] == 'N') {ni -= 1; tari -= 1;}
        if(s[i] == 'S') {ni += 1; tari += 1;}
        if(s[i] == 'W') {nj -= 1; tarj -= 1;}
        if(s[i] == 'E') {nj += 1; tarj += 1;}
        if(tar.find({ni, nj}) != tar.end()) cout << '1';
        else cout << '0';
        tar.insert({tari, tarj});
    }
    cout << endl;
    return 0;
}