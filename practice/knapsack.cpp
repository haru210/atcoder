#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int dp[110][10010];

int main()
{
    int n,w;
    cin >> n >> w;
    int value[n], weight[n];
    rep(i,n) cin >> value[i] >> weight[i];
    for(int i = 0; i <= w; i++) dp[0][i] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if(j >= weight[i]) dp[i+1][j] = max(dp[i][j- weight[i]] + value[i],dp[i][j]); 
            else dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}

//i=0の部分を0でリセットするが、i=1の部分はvalue[0],weight[0]を使いたいので、配るdpのほうが簡潔
//また、同じものを二つ選べる場合は、dp[i+1][w-weight[i]]からの遷移を考えれば良い