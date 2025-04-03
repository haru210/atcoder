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
    //a, bの配置が、abの連続...abの連続となれば良い
    //A_iに対して並べ替えて成立する可能性のある数字はA_(i-1)とA_(i+1)だけ
    //A_(i-1)の方は1つ前のループで検知出来るためA_iとA_(i+1)のみ比較し続ければ良い
    int t;
    cin >> t;
    rep(i, t)
    {
        int n;
        cin >> n;
        int a[2 * n];
        bool ng[n] = {}; //ng[i] := iが既に隣接しているかどうか
        int place[n][2];
        set<pint> ans; //setで管理することで重複を防ぐ
        rep(j, n)
        {
            place[j][0] = -1;
        }
        rep(j, 2 * n)
        {
            cin >> a[j];
            a[j]--; //0-indexedに変換する
        }
        rep(j, 2 * n - 1)
        {
            if(a[j] == a[j + 1]) ng[a[j]] = true;
        }
        rep(j, 2 * n)
        {
            if(place[a[j]][0] == -1) place[a[j]][0] = j;
            else place[a[j]][1] = j;
        }
        rep(j, 2 * n - 1)
        {
            if(ng[a[j]] || ng[a[j + 1]]) continue;
            vector<int> tmp {place[a[j]][0], place[a[j]][1], place[a[j + 1]][0], place[a[j + 1]][1]};
            sort(tmp.begin(), tmp.end());
            if(tmp[1] - tmp[0] == 1 && tmp[3] - tmp[2] == 1) ans.insert({min(a[j], a[j + 1]), max(a[j], a[j + 1])});
        }
        cout << ans.size() << endl;
    }
    return 0;
}