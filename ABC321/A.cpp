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
    int cnt = 0;
    for(int i = 1; i <= 1000; i++){
        int n = i;
        bool ok = true;
        int before;
        before = (n % 10);
        n /= 10;
        while(n > 0)
        {
            int tmp;
            tmp = n % 10;
            if(before >= tmp)
            {
                ok = false;
                break;
            } 
            else
            {
                before = tmp;
                n /= 10;
            }
        }
        if(ok)
        {
            cnt++;
            cout << i << ' ';
        }
    }
    cout << endl;
    cout << cnt;
    return 0;
}