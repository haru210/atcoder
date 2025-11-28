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

class mint
{

    const long long MOD;
    long long x;
    public:
    mint(long long x = 0, long long mod = 1000000007) : MOD(mod), x((x%MOD+MOD)%MOD) {}
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
    
    return 0;
}