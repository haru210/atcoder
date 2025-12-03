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

int sky[2010][2010] = {};
int cloud_sum[2010][2010] = {};
int main()
{
    int n;
    cin >> n;
    int u[n];
    int d[n];
    int l[n];
    int r[n];
    rep(i, n)
    {
        cin >> u[i] >> d[i] >> l[i] >> r[i];
    }
    rep(i, n)
    {
        sky[u[i]][l[i]]++;
        sky[u[i]][r[i] + 1]--;
        sky[d[i] + 1][l[i]]--;
        sky[d[i] + 1][r[i] + 1]++;
    }
    rep2(i, 2002)
    {
        rep2(j, 2002)
        {
            cloud_sum[i][j] = cloud_sum[i - 1][j] + sky[i][j];
        }
    }
    rep2(i, 2002)
    {
        rep2(j, 2002)
        {
            cloud_sum[i][j] = cloud_sum[i][j - 1] + sky[i][j];
        }
    }
    int one_cloud[2010][2010] = {};
    rep2(i, 2000)
    {
        rep2(j, 2000)
        {
            if(cloud_sum[i][j] == 1) one_cloud[i][j] = 1;
            else one_cloud[i][j] = 0;
        }
    }
    int one_cloud_sum[2010][2010] = {};
    rep2(i, 2002)
    {
        rep2(j, 2002)
        {
            one_cloud_sum[i][j] = one_cloud_sum[i - 1][j] + one_cloud[i][j];
        }
    }
    rep2(i, 2002)
    {
        rep2(j, 2002)
        {
            one_cloud_sum[i][j] = one_cloud_sum[i][j - 1] + one_cloud[i][j];
        }
    }
    return 0;
}