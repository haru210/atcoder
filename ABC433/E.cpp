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

//大きい数字から順番にXi,Yiが成り立つように埋めていくと、その行(列)が埋められるようになるのXi,Yiになってからで、
//そのときにはXi,Yiが成り立つように埋めるので、大きい数字から順に埋めれば良い(そのマスに自由に埋められる->すでにXi,Yiが埋まっている)
//そのマスが今埋められるようになったこと、とそのマスのある行、列にその数字があることは等価
int main()
{
    int t;
    cin >> t;
    rep(cs, t)
    {
        int n, m;
        cin >> n >> m;
        int x[n];
        int y[m];
        rep(i, n) 
        {
            cin >> x[i];
            x[i]--;
        }
        rep(i, m)
        {
            cin >> y[i];
            y[i]--;
        } 
        int ans[n][m] = {};
        int xpos[n * m] = {}; //xの逆(数iがxのどこに書かれているか)
        int ypos[n * m] = {}; //yの逆
        bool ok = true;
        rep(i, n * m) 
        {
            xpos[i] = -1;
            ypos[i] = -1;
        }
        rep(i, n)
        {
            if(xpos[x[i]] != -1) 
            {
                ok = false;
                break;
            }
            xpos[x[i]] = i;
        }
        rep(i, m)
        {
            if(ypos[y[i]] != -1)
            {
                ok = false;
                break;
            }
        }
        if(!ok)
        {
            cout << "No\n";
            continue;
        }
        //雑に使えるやつque(どっちにもないときに使う)、min(x,y)ごとに入れておくqueを用意
        //最初は使えない状態からmin(x,y)から1つずつ移動させていけばO(N*M)回だから大丈夫？
        queue<pint> okxy;
        queue<pint> minxy[n * m];
        rep(i, n)
        {
            rep(j, m)
            {
                minxy[min(x[i], y[j])].push({y[i], x[i]}); 
            }
        }
        for(int i = n * m - 1; i >= 0; i++)
        {
            if(xpos[i] != -1 && ypos[i] != -1)
            {
                ans[ypos[i]][xpos[i]] = i + 1;
                while(!minxy[i].empty())
                {
                    pint tmp = minxy[i].front();
                    minxy[i].pop();
                    okxy.push(tmp);
                }
                continue;
            }
            if(xpos[i] != -1 || ypos[i] != -1)
            {
                pint anspos = minxy[i].front();
                minxy[i].pop();
                ans[anspos.first][anspos.second] = i + i;
                while(!minxy[i].empty())
                {
                    pint tmp = minxy[i].front();
                    minxy[i].pop();
                    okxy.push(tmp);
                }
                continue;
            }
        }
    }
    return 0;
}