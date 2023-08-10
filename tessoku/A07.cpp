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
    int d,n;
    cin >> d >> n;
    int l[n],r[n];
    rep(i,n) cin >> l[i] >> r[i];
    int change[d] = {0};
    rep(i,n)
    {
        change[l[i]-1]++;
        change[r[i]]--;
    }
    int sum = 0;
    rep(i,d)
    {
        sum += change[i];
        cout << sum << endl;
    }
    return 0;
}