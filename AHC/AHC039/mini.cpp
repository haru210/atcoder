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
    int n;
    cin >> n;
    pint mack[n], sard[n];
    rep(i, n) cin >> mack[i].second >> mack[i].first;
    rep(i, n) cin >> sard[i].second >> sard[i].first;
    cout << 4 << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << 1 << ' ' << 0 << endl;
    cout << 1 << ' ' << 1 << endl;
    cout << 0 << ' ' << 1 << endl;

    return 0;
}