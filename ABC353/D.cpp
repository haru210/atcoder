#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

template <long long mod>
struct modint {
  modint(ll v = 0) : value(normalize(v)) {}
  ll val() const { return value; }
  void normalize() { value = normalize(value); }
  ll normalize(ll v) {
    if (v <= mod && v >= -mod) {
      if (v < 0) v += mod;
      return v;
    }
    if (v > 0 && v < 2 * mod) {
      v -= mod;
      return v;
    }
    if (v < 0 && v > -2 * mod) {
      v += 2 * mod;
      return v;
    }
    v %= mod;
    if (v < 0) v += mod;
    return v;
  }
  modint<mod>& operator=(ll v) {
    value = normalize(v);
    return *this;
  }
  bool operator==(const modint& o) const { return value == o.val(); }
  bool operator!=(const modint& o) const { return value != o.val(); }
  const modint& operator+() const { return *this; }
  const modint& operator-() const { return value ? mod - value : 0; }
  const modint operator+(const modint& o) const {
    return value + o.val();
  }
  modint& operator+=(const modint& o) {
    value += o.val();
    if (value >= mod) value -= mod;
    return *this;
  }
  const modint operator-(const modint& o) const {
    return value - o.val();
  }
  modint& operator-=(const modint& o) {
    value -= o.val();
    if (value < 0) value += mod;
    return *this;
  }
  const modint operator*(const modint& o) const {
    return (value * o.val()) % mod;
  }
  modint& operator*=(const modint& o) {
    value *= o.val();
    value %= mod;
    return *this;
  }
  const modint operator/(const modint& o) const { return operator*(o.inv()); }
  modint& operator/=(const modint& o) { return operator*=(o.inv()); }
  const modint pow(ll n) const {
    modint ans = 1, x(value);
    while (n > 0) {
      if (n & 1) ans *= x;
      x *= x;
      n >>= 1;
    }
    return ans;
  }
  const modint inv() const {
    ll a = value, b = mod, u = 1, v = 0;
    while (b) {
      ll t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return u;
  }
  friend ostream& operator<<(ostream& os, const modint& x) {
    return os << x.val();
  }
  template <typename T>
  friend modint operator+(T t, const modint& o) {
    return o + t;
  }
  template <typename T>
  friend modint operator-(T t, const modint& o) {
    return -o + t;
  }
  template <typename T>
  friend modint operator*(T t, const modint& o) {
    return o * t;
  }
  template <typename T>
  friend modint operator/(T t, const modint& o) {
    return o.inv() * t;
  }

 private:
  ll value;
};
using modint1000000007 = modint<1000000007>;
using modint998244353 = modint<998244353>;

int GetDigit(int num){
	ll digit = 0;
	while(num != 0){
		num /= 10;
		digit++;
	}
	return digit;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int dig[11] = {};
    rep(i, n)
    {
        dig[GetDigit(a[i])]++;
    }
    ll dig_sum = 0;
    ll tmp = 10;
    rep2(i, 10)
    {
        dig_sum += dig[i] * tmp;
        tmp *= 10;
    }
    modint998244353 ans = 0;
    rep(i, n)
    {
        modint998244353 tmpa = a[i];
        ans = ans + (tmpa * i);
        int dig_a = GetDigit(a[i]);
        ll tmp = 1;
        rep(i, dig_a) tmp *= 10;
        dig_sum -= tmp;
        ans = ans + (tmpa * dig_sum);
    }
    cout << ans << endl;
    return 0;
}