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
    int h, w, q;
    cin >> h >> w >> q;
    set<int> row[h];
    set<int> column[w];
    bool broken[h][w] = {};
    int wall = h * w;
    rep(i, h)
    {
        rep(j, w)
        {
            row[i].insert(j);
            column[j].insert(i);
        }
    }
    rep(i, q)
    {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        if(!broken[r][c])
        {
            wall--;
            broken[r][c] = true;
            row[r].erase(c);
            column[c].erase(r);
        }
        else
        {
            auto ho = row[r].lower_bound(c);
            auto ve = column[c].lower_bound(r);
            int right,down,left,up;
            if(ho == row[r].end()) right = inf;
            else right = (*ho);
            if(ve == column[c].end()) down = inf;
            else down = (*ve);
            
            if(ho != row[r].begin())
            {
                ho--;
                left = (*ho);
            }
            else left = -inf;
            if(ve != column[c].begin())
            {
                ve--;
                up = (*ve);
            }
            else up = -inf;
            if(right != inf)
            {
                row[r].erase(right);
                column[right].erase(r);
                broken[r][right] = true;
                wall--;
            }
            if(left != -inf)
            {
                row[r].erase(left);
                column[left].erase(r);
                broken[r][left] = true;
                wall--;
            }
            if(up != -inf)
            {
                row[up].erase(c);
                column[c].erase(up);
                broken[up][c] = true;
                wall--;
            }
            if(down != inf)
            {
                row[down].erase(c);
                column[c].erase(down);
                broken[down][c] = true;
                wall--;
            }
        }
    }
    cout << wall << endl;
    return 0;
}