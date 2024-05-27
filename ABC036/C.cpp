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
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    vector<int> b;
    rep(i, n) b.push_back(a[i]);
        sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    rep(i, n)
    {
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << id << endl;
    }
    return 0;
}