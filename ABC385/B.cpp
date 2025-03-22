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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    string s[h];
    string t;
    rep(i, h) cin >> s[i];
    cin >> t;
    bool visited[h][w] = {};
    int si = x - 1;
    int sj = y - 1;
    int sum = 0;
    if(s[si][sj] == '@')
    {
        sum++;
        visited[si][sj] = true;
    }
    rep(i, t.size())
    {
        if(t[i] == 'U')
        {
            if(si == 0) continue;
            if(s[si-1][sj] == '#') continue;
            si--;
            if(s[si][sj] == '@' && !visited[si][sj]) 
            {
                sum++;
                visited[si][sj] = true;
            }
        }
        if(t[i] == 'D')
        {
            if(si == h - 1) continue;
            if(s[si+1][sj] == '#') continue;
            si++;
            if(s[si][sj] == '@' && !visited[si][sj]) 
            {
                sum++;
                visited[si][sj] = true;
            }
        }
        if(t[i] == 'L')
        {
            if(sj == 0) continue;
            if(s[si][sj - 1] == '#') continue;
            sj--;
            if(s[si][sj] == '@' && !visited[si][sj]) 
            {
                sum++;
                visited[si][sj] = true;
            }
        }
        if(t[i] == 'R')
        {
            if(sj == w - 1) continue;
            if(s[si][sj + 1] == '#') continue;
            sj++;
            if(s[si][sj] == '@' && !visited[si][sj]) 
            {
                sum++;
                visited[si][sj] = true;
            }
        }
    }
    cout << si + 1 << ' ' << sj + 1 << ' ' <<sum << endl;
    return 0;
}