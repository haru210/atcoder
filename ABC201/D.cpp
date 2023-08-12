#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w];
    vector<vector<int>> dp(h+5,vector<int>(w+5)); //高橋-青木の最適に行動したときの値
    rep(i,h) rep(j,w) cin >> a[i][j];
    dp[h-1][w-1] = 0;
    for(int i = h-1; i >= 0; --i)
    {
        for(int j = w-1; j >= 0; --j)
        {
            if(i == h-1 && j == w-1) continue;
            if((i + j) %2 == 0)
            {
                int step;
                int tmp_1=-inf,tmp_2=-inf;
                if(i + 1 < h)
                {
                    if(a[i+1][j] == '+') step = 1;
                    else step = -1;
                    tmp_1 = dp[i+1][j]+step;
                }
                if(j + 1 < w)
                {
                    if(a[i][j+1] == '+') step = 1;
                    else step = -1;
                    tmp_2 = dp[i][j+1]+step;
                }
                dp[i][j] = max(tmp_1,tmp_2);
            }
            else
            {
                int step;
                int tmp_1=inf,tmp_2=inf;
                if(i + 1 < h)
                {
                    if(a[i+1][j] == '+') step = 1;
                    else step = -1;
                    tmp_1 = dp[i+1][j]-step;
                }
                if(j + 1 < w)
                {
                    if(a[i][j+1] == '+') step = 1;
                    else step = -1;
                    tmp_2 = dp[i][j+1]-step;
                }
                dp[i][j] = min(tmp_1,tmp_2);
            }
        }
    }
    if(dp[0][0] > 0) cout << "Takahashi\n";
    else if(dp[0][0] < 0) cout << "Aoki\n";
    else cout << "Draw\n";
    return 0;
}