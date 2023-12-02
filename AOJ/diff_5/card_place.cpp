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
int n,k;
string card[10];
bool used[10] = {false};
set<string> com;
void dfs(vector<string> &a)
{
    if(a.size() == k)
    {
        string tmp = "";
        rep(i, a.size())
        {
            tmp += a[i];
        }
        com.insert(tmp);
    }
    rep(i,n)
    {
        if(!used[i])
        {
            a.push_back(card[i]);
            used[i] = true;
            dfs(a);
            a.pop_back();
            used[i] = false;
        }
    }
    
}
int main()
{
    cin >> n >> k;
    rep(i,n) cin >> card[i];
    rep(i,n)
    {
        used[i] = true;
        vector<string> A;
        dfs(A);
        used[i] = false;
    }
    cout << com.size() << endl;
    return 0;
}