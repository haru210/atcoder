#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    //全部%2が0なら操作を行う
    int n;
    int cnt = 0;
    int a[200];
    bool exist = false;
    cin >> n;
    rep(i, n) cin >> a[i];
    while(!exist)
    {
        rep(i, n)
        {
            if((a[i] %2) == 1)
            {
                exist = true;
            }
        }
        if(!exist)
        {
            rep(i, n) a[i] /= 2;
            cnt++;    
        }
    }
    cout << cnt << endl;
    return 0;
}