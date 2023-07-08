#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int a,b;
    bool key = false;
    cin >> a >> b;
    int tmp = a % 3;
    switch(tmp)
    {
        case 0:
        break;
        case 1:
        if(b == a + 1)key = true;
        break;
        case 2:
        if(b == a + 1)key = true;
    }
    if(key) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}