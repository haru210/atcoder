#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
char a[100][100] = {0};
char b[100][100] = {0};
int main()
{
    int n;
    cin >> n;
    rep(i, n) rep(j,n) cin >> a[i][j];
 
    rep(i,n) rep(j,n)
    {
        if(i == 0 && j == 0) 
        {
            b[0][0] = a[1][0];
        }
        else if(i == 0)
        {
            b[0][j] = a[0][j - 1];
        }
        else if(j == n - 1)
        {
            b[i][j] = a[i - 1][j];
        }
        else if(i == n-1)
        {
            b[i][j] = a[i][j+1];
        }
        else if(j == 0)
        {
            b[i][j] = a[i + 1][j];
        }
        else{
            b[i][j] = a[i][j];
        }
    }
    rep(i,n)
    {
        rep(j,n)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}