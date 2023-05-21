#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string T[4] = {"resare", "esare","remaerd", "maerd"};
    string s;
    bool can = false;
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i = 0; i < s.size();)
    {
        can = false;
        rep(j, 4)
        {
            if(s.substr(i,T[j].size()) == T[j])
            {
                can = true;
                i += T[j].size();
            }
        }
        if(!can) break;
    }
    if(can) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}