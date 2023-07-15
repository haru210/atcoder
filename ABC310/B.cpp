#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int f[100][100] = {0};
int main()
{
    int n,m;
    cin >> n >> m;
    int p[n],c[n];
    bool upper = true;
    bool last = false;
    bool ok = false;
    rep(i,n)
    {
        cin >> p[i] >> c[i];
        rep(j, c[i])cin >> f[i][j];
    }
    rep(i,n)rep(j,n)
        {
            upper = true;
            last = false;
            if(i == j) continue;
            //if(ok)break;
            //iがjの上位互換か調べる
            if(p[i] > p[j]) upper = false;
            map<int,bool> i_f,j_f;
            rep(k,c[i])
            {
                i_f[f[i][k]] = true;
            }
            rep(k,c[j])
            {
                j_f[f[j][k]] = true;
            }
            for(auto [key,val]:j_f)
            {
                if(i_f[key] == false && val != false) upper = false;
            }
            if(p[i] < p[j]) last = true;
            for(auto [key,val]: i_f)
            {
                if(j_f[key] == false && val != false) last = true;
            }
            if(!last) upper = false;
            if(upper)ok = true;
        }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
//>=の余事象は<だし、>の余事象は=<だよ