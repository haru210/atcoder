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
    int h,w;
    int ans = inf;
    cin >> h >> w;
    int a[h][w];
    int b[h][w];
    vector<int> row;
    vector<int> line;
    rep(i,h) rep(j,w) cin >> a[i][j];
    rep(i,h) rep(j,w) cin >> b[i][j];
    rep(i,h) row.push_back(i);
    rep(i,w) line.push_back(i);
    do
    {
        do
        {
            int copy[h][w] = {};
            rep(i,h) rep(j,w) copy[i][j] = a[row[i]][line[j]];
            bool ok = true;
            rep(i,h) rep(j,w) if(copy[i][j] != b[i][j]) ok = false;
            int tmp = inf;
            if(ok)
            {
                tmp = 0;
                for(int i = 0; i < h; i++) for(int j = i - 1; j >= 0; j--) if(row[i] < row[j]) tmp++;
                for(int i = 0; i < w; i++) for(int j = i - 1; j >= 0; j--) if(line[i] < line[j]) tmp++;
            }
            ans = min(ans, tmp);
        }while(next_permutation(line.begin(), line.end()));
    }while(next_permutation(row.begin(), row.end()));
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}