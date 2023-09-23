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
    ll k;
    cin >> k;
    ll num = 0;
    int digit = 1;
    int dig_num[12] = {0};
    rep(i,k)
    {
        dig_num[0]++;
        rep(j,digit-1)
        {
            if(dig_num[j] >= dig_num[j+1])
            {
                if(j == 0) dig_num[j] = 0;
                else
                {
                    dig_num[j] = dig_num[j-1] + 1;
                }
                dig_num[j+1]++;
            }
        }
       if(dig_num[digit - 1] >= 10)
        {
            digit++;
            dig_num[0] = 0;
            rep2(j,digit - 1)
            {
                dig_num[j] = dig_num[j-1] + 1;
            }
        }
    }
    rep(i,digit)
    {
        num += (dig_num[i] * pow(10,i));
    }
    cout << num << endl;
    return 0;
}