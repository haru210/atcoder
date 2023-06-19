#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int x[100], y[100];
int u[300], v[300], w[300];
int a[5000], b[5000];
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    rep(i, n) cin >> x[i] >> y[i];
    rep(i, m) cin >> u[i] >> v[i] >> w[i];
    rep(i, k) cin >> a[i] >> b[i];
    rep(i, n) cout << 5000 << ' ';
    cout << endl;
    rep(i, m) cout << 1 << ' ';
    cout << endl;
    return 0;
}