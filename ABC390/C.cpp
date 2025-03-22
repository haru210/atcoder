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

//黒マスの端を記憶、その範囲を埋め尽くす
int main()
{
    int h, w;
    cin >> h >> w;
    string s[h];
    int left = inf;
    int right = -1;
    int top = inf;
    int bottom = -1;
    rep(i, h) cin >> s[i];
    rep(i, h)
    {
        rep(j, w)
        {
            if(s[i][j] == '#')
            {
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }
    }
    bool ans = true;
    for(int i = top; i <= bottom; i++)
    {
        for(int j = left; j <= right; j++)
        {
            if(s[i][j] == '.')
            {
                ans = false;
                break;
            }
        }
        if(!ans) break;
    }
    YesNo(ans);
    return 0;
}