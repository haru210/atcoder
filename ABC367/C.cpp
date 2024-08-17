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

int r[10];
int n, k;
vector<int> a;
int sum = 0;
void dfs(int depth)
{
    rep(i, r[depth])
    {
        a.push_back(i + 1);
        sum += i + 1;
        if(depth + 1 == n)
        {
            if(sum % k == 0)
            {
                rep(j, a.size())
                {
                    cout << a[j];
                    if(j != a.size() - 1) cout << ' ';
                    else cout << endl;
                }
            }
        }
        else
        {
            dfs(depth + 1);
        }
        a.pop_back();
        sum -= i + 1;
    }
}
int main()
{
    cin >> n >> k;
    rep(i, n) cin >> r[i];
    dfs(0);
    return 0;
}