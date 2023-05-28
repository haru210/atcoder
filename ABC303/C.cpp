#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

tuple<int,int,bool> cure;

int main()
{
    int n, m, h, k;
    int x = 0, y = 0;
    string s;
    map<pair<int,int>, bool> cure;
    pair<int,int> position;
    cin >> n >> m >> h >> k >> s;
    int hp = h;
    bool success = true;
    rep(i, m)
    {
        pair<int, int> a;
        cin >> a.first >> a.second;
        cure[a] = true;
    }
    rep(i, n)
    {
        //移動
        switch(s[i])
        {
            case 'R':
            x++;
            break;
            case 'L':
            x--;
            break;
            case 'U':
            y++;
            break;
            case 'D':
            y--;
            break;
        }
        //体力チェック
        hp--;
        if(hp < 0)
        {
            success = false;
            break;
        }
        //アイテムチェック
        position.first = x;
        position.second = y;
        if(cure[position] && hp < k)
        {
            hp = k;
            cure[position] = false;
        }
    }
    if(success) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}