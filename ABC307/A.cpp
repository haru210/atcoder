#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int a;
    int sum = 0;
    cin >> n;
    rep(i, n)
    {
        if(i != 0) cout << ' ';
        rep(j,7)
        {
            cin >> a;
            sum+= a;
        }
        cout << sum;
        sum = 0;
    }
    cout << endl;
    return 0;
}