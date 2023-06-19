#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
//全マス見て最初に見たもの=左上
//左上が欠ける場合=そのマスが.かつ右と下が#
//最後に見たもの=右下
//右下が欠ける場合=そのマスが.かつ左と上が#
char state[500][500];
int main()
{
    int h, w;
    pair<int, int> left_top;
    pair<int ,int> right_under;
    pair<int, int> eaten;
    bool isfirst = false;
    bool end = false;
    cin >> h >> w;
    rep(i, h) 
    {
        rep(j, w) cin >> state[i][j];
    }

    rep(i, h) 
    {
        rep(j, w)
        {

            if(end) break;
            if((state[i][j] == '#') && (!isfirst))
            {
                left_top.first = i;
                left_top.second = j;
                isfirst = true;
            }
            else if(!(i >= h - 1) && !(j >= w - 1) && !isfirst)
            {
                if(state[i+1][j] == '#' && state[i][j+1] == '#' && state[i][j] == '.'){
                    eaten.first = i;
                    eaten.second = j;
                end = true;
                }
            }
            else if(state[i][j] == '#')
            {
                right_under.first = i;
                right_under.second = j;
            }
            else if((i > 0) && (j > 0))
            {
                if(state[i][j] == '.' && state[i-1][j] == '#' && state[i][j-1] == '#')
                {
                    right_under.first = i;
                    right_under.second = j; 
                }
            }
        }
    }
   // cout << left_top.first << ' ' << left_top.second << endl;
    for(int i = left_top.first; i <= right_under.first; i++ )
    {
        if(end) break;
        for(int j = left_top.second; j <= right_under.second; j++)
        {
            if(end) break;
            if(state[i][j] == '.')
            {
                eaten.first = i;
                eaten.second = j;
                end = true;
            }
        }
    }
    eaten.first++;
    eaten.second++;
    cout << eaten.first << ' ' << eaten.second << endl;
    return 0;
}