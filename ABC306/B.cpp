#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    unsigned long long sum = 0;
    rep(i, 64)
    {
        unsigned long long a;
        cin >> a;
        sum += a << i;
    }
    cout << sum << endl;
    return 0;
}