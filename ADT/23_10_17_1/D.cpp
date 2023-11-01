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
int main()
{
    int n,m;
    cin >> n >> m;
    set<int> s[m];
    rep(i,m)
    {
        int k;
        cin >> k;
        int tmp;
        rep(j,k)
        {
            cin >> tmp;
            tmp--; //0-indexedにする
            s[i].insert(tmp);
        }
    }
    bool ans = true;
    rep(i,n)
    {
        rep(j,n)
        { 
            if(i == j) continue;
            bool ok = false;
            rep(l,m)
            {
                if((s[l].find(i) != s[l].end()) && (s[l].find(j) != s[l].end()))
                {
                    ok = true;
                    break;
                }
            }
            if(!ok) ans = false;
        }
    }
    YesNo(ans);
    return 0;
}