#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int n;
    vector<int> div;
    cin >> n;
    rep2(i,min(n,9))
    {
        if(n % i == 0) div.push_back(i);
    }
    cout << 1;
    rep2(i,n)
    {
        bool key = false;
        rep(j,div.size())
        {
            if(i % (n/div[j]) == 0) 
            {
                cout << div[j];
                key = true;
                break;
            }
        }
        if(!key) cout << '-';
    }
    cout << endl;
    return 0;
}