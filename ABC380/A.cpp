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
    string s;
    cin >> s;
    int cnt[4] = {};
    rep(i, s.size())
    {
        if(s[i] == '1') cnt[1]++;
        if(s[i] == '2') cnt[2]++;
        if(s[i] == '3') cnt[3]++; 
    }
    if(cnt[1] == 1 && cnt[2] == 2 && cnt[3] == 3) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}