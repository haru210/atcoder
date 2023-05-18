#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int a[100][100] = {0};
int main()
{
    int h, w;
    cin >> h >>w;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> a[i][j];
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if(a[i][j] == 0)
            {
                cout << '.';
            }
            else
            {
                a[i][j]--;
                cout << static_cast<char>('A' + a[i][j]);
            }
        }
        cout << endl;
    }
    return 0;
}