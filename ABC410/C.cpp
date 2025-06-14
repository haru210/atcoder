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

int main()
{
    //タイプ3は先頭の位置を帰る操作に相当
    int n, q;
    cin >> n >> q;
    int a[n];
    int first_pos = 0;
    rep(i, n)
    {
        a[i] = i + 1;
    }
    rep(i, q)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;
            int pos = (p + first_pos) % n;
            a[pos] = x;
        }
        if(type == 2)
        {
            int p;
            cin >> p;
            p--;
            int pos = (p + first_pos) % n;
            cout << a[pos] << endl;
        }
        if(type == 3)
        {
            int k;
            cin >> k;
            first_pos += k;
            first_pos %= n;
        }
    }
    return 0;
}