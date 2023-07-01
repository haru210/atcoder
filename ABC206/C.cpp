#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int a[300000];
//全体の組み合わせからA_i=A_jとなる組み合わせ数を引く
int main()
{
    ll n;
    ll tmp;
    ll sum;
    map<int, ll> cnt;
    cin >> n;
    rep(i, n)
    {
        cin >> tmp;
        cnt[tmp]++;
    }
    sum = n*(n-1)/2;
    for(auto [key, val] : cnt)
    {
        sum -= val*(val-1)/2;
    }
    cout << sum << endl;
    return 0;
}