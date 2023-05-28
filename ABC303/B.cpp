#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n, m;
    cin >> n >> m;
    bool check[51][51] = {false};
    int a[51][51];
    int sum = 0;
    rep(i, m)
    {
        rep(j, n) 
        {
            cin >> a[i][j];
        }
    }
    rep(i, m)
    {
        for(int j = 0; j < n - 1; j++)
        {
            int first = a[i][j];
            int second = a[i][j + 1];
            //0-indexedに
            first--;
            second--;
            check[first][second] = true;
            check[second][first] = true;
        }
    }
    //check
    
    rep(i, n)
    {
        rep(j, n)
        {
            if(!check[i][j] && i != j)
            {
                sum++;
                check[i][j] = true;
                check[j][i] = true;
            }
        }
    }
    cout << sum << endl;
    return 0;
}