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

int main()
{
    int n;
    cin >> n;
    char ans[n + 1][n + 1];
    rep2(i, n)
    {
        int j = n + 1 - i;
        if(i <= j)
        {
            char color;
            if(i % 2 == 1)
            {
                color = '#';
            }
            else
            {
                color = '.';
            }
            for(int ii = i; ii <= j; ii++)
            {
                for(int jj = i; jj <= j; jj++)
                {
                    ans[ii][jj] = color;
                }
            }
        }
    }
    rep2(i, n)
    {
        rep2(j, n)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}