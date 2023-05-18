#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, a, b;
    int sum = 0;
    int c[300];
    cin >> n >> a >> b;
    rep(i, n)
    {
        cin >> c[i];
    }
    sum = a + b;
    rep(i, n)
    {
        if(c[i] == sum)
        {
            cout << i + 1 << endl;
        }
    }
    return 0;
}