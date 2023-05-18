#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b, c, x;
    int sum = 0;
    int cnt = 0;
    cin >> a >> b >> c >> x;
    for(int i = 0; i <= a; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            for(int k = 0; k <= c; k++)
            {
                sum = (i * 500) + (j * 100) + (k * 50);
                if(sum == x) cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}