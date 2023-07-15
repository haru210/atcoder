#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int a[200000],b[200000];

pair<ll,int> p[200000];
int main()
{
    int n;
    cin >> n;
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n)
    {
        p[i].first = a[i] * (a[i] + b[i]);
        p[i].first *= -1;
        p[i].second = i + 1;
    }
    sort(p,p+n);
    rep(i,n - 1)
    {
        cout << p[i].second << ' ';
    }
    cout << p[n - 1].second << endl;
    return 0;
}