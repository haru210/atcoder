#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i,n)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int prev = a[0];
    for(int i = 1; i < n; i++)
    {
        if(prev + 1 != a[i])
        {
            cout << prev + 1 << endl;
            break;
        }
        prev = a[i];
    }
    return 0;
}