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

#include<bits/stdc++.h>

class mint
{

    const long long MOD;
    public:
    long long x;
    mint(long long x = 0, long long mod =998244353 ) : MOD(mod), x((x%MOD+MOD)%MOD) {}
    mint operator-() const {
        return mint(-x);
    }
    mint& operator+=(const mint& num)
    {
        if((x += num.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator -=(const mint& num)
    {
        if((x += MOD-num.x) >= MOD) x= MOD;
        return *this;
    }
    mint& operator*=(const mint& num)
    {
        (x *= num.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint& a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint& a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint inv() const
    {
        long long a = x;
        long long b = MOD, u = 1, v = 0;
        while(b) 
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= MOD;
        if(u < 0) u += MOD;
        return u;
    }

    mint& operator/=(const mint& a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const
    {
        mint res(*this);
        return res /= a;
    }

    friend ostream& operator<<(ostream& os, const mint& m)
    {
        os << m.x;
        return os;
    }
};
int main()
{
    //自分より大きい数の分だけマイナスの差分をつける
    ll n, m;
    cin >> n >> m;
    ll a[n];
    ll b[m];
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    //各ai, biに対して、その数がbの配列より大きい分は+、小さい分は-として見ることができる
    //同じ時は、bだけ-と見る
    mint ans(0);
    rep(i, n)
    {
        ll pos = upper_bound(b, b + m, a[i]) - b;
        ans += a[i] * pos - a[i] * (m - pos);
    }
    rep(i, m)
    {
        ll pos = lower_bound(a, a + n, b[i]) - a;
        ans += b[i] * pos - b[i] * (n - pos);
    }
    cout << ans.x << endl;
    return 0;
}