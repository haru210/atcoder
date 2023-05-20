#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, y;
    int k = 0;
    int sum = 0;
    bool key = false;
    cin >> n >> y;
    //2重ループ+Yの枚数から逆算を用いて全探索する
    rep(i, n + 1)
    {
        rep(j,n + 1 - i)    //N枚を超えることを回避する
        {
            k = n - (i + j);
            sum = 10000 * i + 5000 * j + 1000 * k;
            if(sum == y)
            {
                cout << i << ' ' << j << ' ' << k << endl;
                key = true;
                break;
            }
        }
        if(key) break;
    }
    if(!key)
    {
        cout << "-1 -1 -1\n";
    }
    return 0;
}