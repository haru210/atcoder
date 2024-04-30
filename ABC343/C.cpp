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
    ll n;
    vector<ll> pV; //回文立方数の列挙
    cin >> n;
    for(ll i = 0; (i * i * i) <= n; i++)
    {
        bool ok = true;
        string s = to_string((i * i * i));
        int left = 0;
        int right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
            {
                ok = false;
                break;
            }
            left++;
            right--;
        }
        if(ok) pV.push_back((i * i * i));
    }
    cout << pV[pV.size() - 1] << endl;
    return 0;
}