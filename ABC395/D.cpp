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

//種類2では巣をswapすると考える
//種類1では、

int main()
{
    int n, q;
    cin >> n >> q;
    int pigeon[n + 1]; //種類1によって鳩が移動した先  
    int name[n + 1]; //種類2によって、元々iだった巣が今どこにいるか
    int invname[n + 1]; //種類2によて、今iである巣が元々何処だったか
    rep2(i, n)
    { 
        pigeon[i] = i;
        name[i] = i;
        invname[i] = i;
    } 
    rep(i, q)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int a, b;
            cin >> a >> b;
            pigeon[a] = invname[b]; //今bである箱に入れたい
        }
        if(op == 2)
        {
            //今aになっているところと今bになっている所を入れ替える
            int a, b;
            cin >> a >> b;
            swap(invname[a], invname[b]); 
            //a, bを入れ替えたいので、要素がa,bになるところ、すなわちinvname[a], invname[b]をswapする
            swap(name[invname[a]], name[invname[b]]);

        }
        if(op == 3)
        {
            int a;
            cin >> a;
            cout << name[pigeon[a]] << endl; //もともとpigeon[a]だった箱を出力したい
        }
    }
    return 0;
}