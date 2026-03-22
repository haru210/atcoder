#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

vector<int> sq;
//0, r, 0, uの黒を数える
ll countBlack(ll j, ll i)
{
    //最大の正方形分を足して、そこからは黒白が1行(列)ごとに交互に現れる
    if (i == 0 || j == 0) return (max(i, j) / 2 + 1);
    ll sq_max = min(i, j) / 2 + 1;
    ll ans = 2 * sq_max * sq_max - sq_max;
    if (i == j) return ans;
    if (min(i, j) % 2 == 0)
    {
        ans += ((max(i, j) - min(i, j)) / 2) * (min(i, j) + 1);
    }
    else
    {
        ans += (max(i, j) - min(i, j) + 1) / 2 * (min(i, j) + 1);
    }
    return ans;
}
//l, r, 0, uの数を数える
ll countBlackUp(ll l, ll r, ll u)
{
    if (l == 0) return countBlack(r, u);
    if (l > 0)
    {
        return countBlack(r, u) - countBlack(l - 1, u);
    }
    if (l < 0)
    {
        return countBlack(r, u) + countBlack(-l, u) - countBlack(0, u);
    }
}

int main()
{
    //4象限に分けて、各象限に大して(0,0)から(i,j)までの数を数える
    //(0,0)と、(i, 0), (j,0)を重ねて数えた分減算する
    ll l, r, d, u;
    cin >> l >> r >> d >> u;
    if (u < 0) {u *= -1; d *= -1; swap(u, d);}
    if (r < 0) {r *= -1; l *= -1; swap(r, l);}
    if (d == 0)
    {
        cout << countBlackUp(l, r, u) << endl;
    }
    if (d > 0)
    {
        cout << countBlackUp(l, r, u) - countBlackUp(l, r, d - 1) << endl;
    }
    if (d < 0)
    {
        cout << countBlackUp(l, r, u) + countBlackUp(l, r, -d) - countBlackUp(l, r, 0) << endl;

    }
    return 0;
}
