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

int main()
{
    int n, a;
    cin >> n >> a;
    queue<int> que;
    int t[n];
    rep(i, n)
    {
        cin >> t[i];
    }
    ll time = t[0];
    time += a;
    cout << time << endl;
    rep2(i, n - 1)
    {
        if(time < t[i]) time = t[i];
        time += a;
        cout << time << endl;
    }
    return 0;
}