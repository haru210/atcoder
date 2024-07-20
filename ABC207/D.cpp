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

const long double Ex = 1e-10;
class Complex
{
    public:
        long double re;
        long double im;
        Complex(long double r, long double i);
        Complex(const Complex& z);
        Complex();
        long double abs() const; //絶対値
        long double norm() const;  //絶対値の2乗
        Complex conj() const;  //共役複素数
        Complex& operator=(const Complex& z);
        Complex operator+(const Complex& z);
        Complex operator+(const long double& r);
        Complex operator-(const Complex& z);
        Complex operator-(const long double& r);
        Complex operator*(const Complex& z);
        Complex operator*(const long double& r);
        Complex operator/(const Complex& z);
        Complex operator/(const long double& r);
};
Complex::Complex(long double r, long double i)
{
    re = r;
    im = i;
}
Complex::Complex(const Complex& z)
{
    re = z.re;
    im = z.im;
}
Complex::Complex()
{
    re = 0;
    im = 9;
}
long double Complex::norm() const
{
    return re * re + im * im;
}
long double Complex::abs() const
{
    return sqrt(norm());
}
Complex Complex::conj() const
{
    return Complex(re, -im);
}
Complex& Complex::operator=(const Complex& z)
{
    re = z.re;
    im = z.im;
    return *this;
}
Complex Complex::operator+(const long double& r)
{
    return Complex(re + r, im);
}
Complex Complex::operator+(const Complex& z)
{
    return Complex(re + z.re, im + z.im);
}
Complex Complex::operator-(const long double& r)
{
    return Complex(re - r, im);
}
Complex Complex::operator-(const Complex& z)
{
    return Complex(re - z.re, im - z.im);
}
Complex Complex::operator*(const Complex& z)
{
    return Complex(re * z.re - im * z.im, re * z.im + im * z.re);
}
Complex Complex::operator*(const long double& r)
{
    return Complex(re * r, im * r);
}
Complex Complex::operator/(const long double& r)
{
    return Complex(re / r, im / r);
}
Complex Complex::operator/(const Complex& z) 
{
    Complex tmp;
    tmp = (*this);
    tmp = tmp * (z.conj() / z.norm());
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    vector<Complex> s(n), t(n);
    rep(i, n)
    {
        cin >> s[i].re >> s[i].im;
    }
    rep(i, n)
    {
        cin >> t[i].re >> t[i].im;   
    }
    //s[0]が0になるように平行移動し、t[i]が0になるようにそれぞれ平行移動し回転で重なるかを見る
    bool ans = false;
    if(n == 1) ans = true;
    rep(i, n)
    {
        vector<Complex> st(n), tt(n);
        rep(j, n)
        {
            st[j] = s[j] - s[0];
            tt[j] = t[j] - t[i]; 
        }
        //s[1]とt[j]が合うように回転移動する
        rep(j, n)
        {
            if(i == j) continue;  //s0とすでに重なっているので  
            if(abs(tt[j].abs() - st[1].abs()) > Ex) continue; //絶対値が違ったら重ならない  

            vector<Complex> stt(n), ttt(n);
            Complex rot = tt[j] / st[1];
            rep(k, n)
            {
                stt[k] = st[k] * rot;
                ttt[k] = tt[k];
            }
            auto cmp = [&](Complex a, Complex b) -> bool 
            {
                return (abs(a.re - b.re) > Ex ? a.re < b.re : a.im < b.im);
            };
            bool same = true;
            sort(stt.begin(), stt.end(), cmp);
            sort(ttt.begin(), ttt.end(), cmp);
            rep(k, n)
            {
                if((stt[k] - ttt[k]).abs() >= Ex) 
                {
                    same = false;
                }
            }
            if(same)
            {
                ans = true;
            }
        }
    }
    YesNo(ans);
    return 0;
}