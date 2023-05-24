#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    int cnt = 0;
    bool key = false;
    cin >> n >> m;
    vector<string> s(n);
    string T;
    rep(i, n)
    {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    do
    {
        key = true;
        rep(i, n - 1) 
        {
            cnt = 0;
            rep(j, m)
            {
                if(s[i][j] != s[i+1][j]) cnt++;
            }
            if(cnt != 1) key = false; 
        }
        if(key)
        {
            cout << "Yes\n";
            return 0;
        }
    }while(next_permutation(s.begin(),s.end()));
    cout << "No\n";
    return 0;
}
