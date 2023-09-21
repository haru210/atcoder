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

bool check(string s,int left,int right)
{
    bool ok = true;
    while(left < right)
    {
        if(s[left] != s[right]) ok = false;
        left++;
        right--;
        if(!ok) break;
    }
    if(ok) return true;
    else return false;
}
int main()
{
    string s;
    cin >> s;
    int ans = 1;
    int n = s.size();
    rep(i,n)
    {
        for(int j = i+1; j < s.size(); j++)
        {
            if(check(s,i,j)) ans = max(ans,j - i + 1);
        }
    }
    cout << ans;
    return 0;
}