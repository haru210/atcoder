#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    string s,t;
    cin >> s >> t;
    int s_size,t_size;
    bool key = false;
    s_size = s.size();
    t_size = s.size();
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    reverse(t.begin(),t.end());
            
    if(s < t) cout << "Yes\n";
    else cout << "No\n";
        return 0;
}

