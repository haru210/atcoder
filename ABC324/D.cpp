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

ll GetDigit(ll num){
	ll digit = 0;
	while(num != 0){
		num /= 10;
		digit++;
	}
	return digit;
}
int main()
{
    int n;
    ll max_s = 0;
    ll ans = 0;
    string s;
    ll s_cnt[10] = {0};
    cin >> n >> s;
    rep(i,n)
    {
        int tmp = s[i] - '0';
        s_cnt[tmp]++;
    }
    sort(s.begin(),s.end());
    ll e = 1;
    rep(i,n)
    {
        ll tmp = s[i] - '0';
        tmp *= e;
        max_s += tmp;
        e *= 10;
    }
    if(s == "0") ans++;
    for(ll i = 1; i * i <= max_s; i++)
    {
        ll sq = i*i;
        ll digit = GetDigit(sq);
        string sq_string = "";
        rep(j,n - digit) sq_string += "0";
        sq_string += to_string(sq);
        ll sq_cnt[10] = {0};
        rep(j,sq_string.size())
        {
            ll tmp = sq_string[j] - '0';
            sq_cnt[tmp]++;
        }
        bool ok = true;
        rep(j,10)
        {
            if(s_cnt[j] != sq_cnt[j]) ok = false;
        }
        if(ok) ans++;
    }
    
    cout << ans << endl;
    return 0;
}