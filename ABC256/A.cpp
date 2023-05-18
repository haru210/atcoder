#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    int sum  = 1;
    cin >> n;
    rep(i, n)
    {
        sum *= 2;
    }
    cout << sum << endl;
    return 0;
}