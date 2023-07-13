#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int a,b;
    int sum;
    cin >> a >> b;
    sum = a + b;
    if(sum % 2 == 0)
    {
        cout << sum / 2 << endl;
    }
    else
    {
        cout << sum / 2 + 1 << endl;
    }
    return 0;
}