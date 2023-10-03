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
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    vector<int> odd; //奇数
    vector<int> even; //偶数
    rep(i,n)
    {
        if(a[i] %2 == 0) even.push_back(a[i]);
        else odd.push_back(a[i]);
    }
    if(odd.size() <= 1 && even.size() <= 1) cout << -1 << endl;
    else
    {
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        int x1 = -1,x2 = -1;
        if(odd.size() >= 2) x1 = odd[0]+odd[1];
        if(even.size() >= 2) x2 = even[0] + even[1];
        
        cout << max(x1,x2)<< endl;
    }
    return 0;
}