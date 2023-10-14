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
    ll n;
    bool ok = true;
    cin >> n;
    if(n != 1){
        while(true)
        {
            if(n %2 == 0) n/= 2;
            else if(n %3 == 0) n/= 3;
            else
            {
                ok = false;  
                break;  
            }
            if(n == 1) break;
        }
    }
    YesNo(ok);
    return 0;
}