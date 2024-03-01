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
    //入力
    int n,m, k;
    int ans = 0;
    cin >> n >> m;
    int a[m], b[m];
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
    cin >> k;
    int c[k], d[k];
    for(int i = 0; i < k; i++) cin >> c[i] >> d[i];

    for(int i = 0; i < (1 << k); i++)
    {
        int dishes[n] = {}; //皿の状態を管理する
        int tmp = 0; //現在のパターンの条件を満たす数
        for(int j = 0; j < k; j++)
        {
            //1の時Cに、0の時Dに置く
            if(i & (1<<j))
            {
                dishes[c[j] - 1]++;
            }
            else
            {
                dishes[d[j] - 1]++;
            }
        }

        //条件を満たす数を数える
        for(int j = 0; j < m; j++)
        {
            if(dishes[a[j] - 1] > 0 && dishes[b[j] - 1] > 0) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}