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
    char s[3];
    cin >> s[0] >> s[1] >> s[2];
    int num[3] = {};
    if(s[0] == '>')
    {
        num[0]++;
    }
    else
    {
        num[1]++;
    }
    if(s[1] == '>')
    {
        num[0]++;
    }
    else
    {
        num[2]++;
    }
    if(s[2] == '>')
    {
        num[1]++;
    }
    else
    {
        num[2]++;
    }
    rep(i, 3)
    {
        if(num[i] == 1) cout << (char)(i + 'A') << endl;
    }
    return 0;
}