#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i, n)
    {
        cout << s[i] << s[i];
    }
    cout << endl;
    return 0;
}