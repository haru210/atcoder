#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    int tmp;
    int a, b;
    cin >> n;
    tmp = n / 5;
    a = tmp * 5;
    b = (tmp + 1) * 5;
    if(b - n > n - a)
    {
        cout << a << endl;
    }
    else 
    {
        cout << b << endl;
    }
    return 0;
}