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
    int volume = 0;
    bool playing = false;
    int q;
    cin >> q;
    rep(i, q)
    {
        int a;
        cin >> a;
        if (a == 1) volume++;
        if (a == 2)
        {
            if (volume >= 1) volume--;
        }
        if (a == 3)
        {
            playing = !playing;
        }
        bool ok = false;
        if (volume >= 3 && playing) ok = true;
        YesNo(ok);
    }
    return 0;
}
