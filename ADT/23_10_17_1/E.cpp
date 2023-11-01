#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n,m;
    cin >> n >> m;
    int a[n];
    int b[m];
    vector<int> c;
    rep(i,n)
    {
        cin >> a[i];
        c.push_back(a[i]);
    }
    rep(i,m)
    {
        cin >> b[i];
        c.push_back(b[i]);
    }
    sort(c.begin(),c.end());
    rep(i,n-1)
    {
        cout << (lower_bound(c.begin(),c.end(),a[i] ) - c.begin())+1<< ' ';
    }
    cout << (lower_bound(c.begin(),c.end(),a[n-1]) - c.begin())+1 << endl;
    rep(i,m-1)
    {
        cout << (lower_bound(c.begin(),c.end(),b[i]) - c.begin())+1 << ' ';
    }
    cout << (lower_bound(c.begin(),c.end(),b[m-1]) - c.begin())+1 << endl;

    return 0;
}