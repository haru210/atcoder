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
    int a,b,c;
    cin >> a >> b >> c;
    int sum = 0;
    sum += 7 - a;
    sum += 7 - b;
    sum += 7 - c;
    cout << sum << endl;
    return 0;
}