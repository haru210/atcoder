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
	int n;
	cin >> n;
	int h[n+1];
	rep2(i,n) cin >> h[i];
	int dp[n+1];
	rep(i,n+1) dp[i] = inf;
	dp[1] = 0;
	rep2(i,n-1)
	{
		dp[i+1] = min(dp[i+1],dp[i] + abs(h[i] - h[i+1]));
		if(i == n-1) continue;
		dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
	}
	cout << dp[n] << endl;
	return 0;
}