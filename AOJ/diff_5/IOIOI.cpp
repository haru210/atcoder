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
    int n,m;
    string s;
    int ans = 0;
    cin >> n >> m >> s;
    //s[i]文字目からのPnがあったとき,s[i]+2からはP(n-1)が必ずある
    //逆にs[i]からのPnの終点の次の文字以降からしかPn以上のものは存在しない
    //Pnが見つかっていないor終点まで来たら探索、それ以外はs[i]-2を参照
    int level[m] = {0}; //level[i] := i文字目からのPnのnの値
    int before = 0;
    int right = -1; //PnがあったときPnの終点を記録する
    rep(i,m - 2*n)
    {
        if(s[i] == 'O') continue;
        if(i <= right)
        {
            level[i] = before;
            before--;
        }
        else
        {
            for(int j = i + 1; j +1 < m; j += 2)
            {
                if(s[j] == 'O' && s[j+1] == 'I') level[i]++;
                else break;
            }
            if(level[i] > 0)
            {
                before = level[i] - 1;
                right = level[i] *2 + i;
            }            
        }
    }
    rep(i,m)
    {
        if(level[i] >= n) ans++;
    }
    cout << ans << endl;
    return 0;
}