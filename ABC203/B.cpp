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
    int sum = 0;
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            sum += i*100 + j;
        }
    }
    cout << sum << endl;
    return 0;
}