#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char c[100][100];

int main()
{
    int h, w;
    int n;
    cin >> h >> w;
    n = min(h, w);
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> c[i][j];
        }
    }
    
    return 0;
}