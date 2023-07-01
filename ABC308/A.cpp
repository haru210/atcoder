#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int s[8];
    rep(i, 8) cin >> s[i];
    bool key = true;
    if(s[0] < 100 || s[0] > 675) key = false;
    if(s[0] %25 != 0) key = false;
    for(int i = 1; i < 8; i++)
    {
        if(s[i-1] > s[i]) key = false;
        if(s[i] < 100 || s[0] > 675) key = false;
        if(s[i] %25 != 0) key = false;
    }
    if(key) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}