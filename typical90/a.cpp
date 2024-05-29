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
//何cmにできるか二分探索する
int n, l, k;
int a[100000];
bool canCut(int sc)
{
    int choosed = 0;
    int last_choosed = -1;
    int nl = 0;
    rep(i, n)
    {
        if(last_choosed == -1) nl = a[i];
        nl = a[i] - a[last_choosed];
        if(nl >= sc)
        {
            choosed++;
            last_choosed = i;
        }
        if(choosed >= k) break;
    }
    if(choosed >= k)
    {
        if(l - a[last_choosed] >= sc) return true;
        else return false;
    }
    else return false;
}
int main()
{
    cin >> n >> l >> k;
    rep(i, n) cin >> a[i];
    int ok = -1;
    int ng = l;
    int mid;
    while(ng - ok > 1)
    {
        mid = (ok + ng) / 2;
        if(canCut(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}