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
    int n, m;
    cin >> n >> m;
    int a[m];
    char b[m];
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
    }
    bool taroed[n] = {};
    rep(i, m)
    {
        if(b[i] == 'F')
        {
            cout << "No\n";
        }
        else
        {
            if(!taroed[a[i]])
            {
                taroed[a[i]] = true;
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}