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
int order[3] = {0,1,2};
int main()
{
    int m;
    ll ans = inf;
    cin >> m;
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    //どの数字をどの順番で止めるか全探索
    //i->どの数字で止めるか
    //j->何番目に止めるか
    //k->今何文字目か
    //cntそのリールを見始めて何秒立ったか
    rep(i,10)
    {
        do{
            ll sec = 0;
            int k = 0;
            bool ok = true;
            rep(j,3)
            {
                int cnt = 0;
                while(cnt < m)
                {
                    int tmp = s[order[j]][k] - '0';
                    if(tmp == i)
                    {
                        if(j != 2)sec++;
                        if(k == m - 1) k = 0;
                        else k++;
                        break;
                    }
                    sec++;
                    cnt++; 
                    if(k == m - 1) k = 0;
                    else k++;
                }
                if(cnt == m)
                {
                    ok = false;
                    break;
                }
            }  
            if(ok)ans = min(sec,ans);
        }while(next_permutation(order,order+3));
    }
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}