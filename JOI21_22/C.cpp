#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int sum[51][51] = {};
int calc_sum(int x1,int y1,int x2, int y2)
{
    //sum[3][1] - sum[1][0] - sum[0][3] + sum[0][0];
    return sum[y2][x2] - sum[y2][x1-1] - sum[y1-1][x2] + sum[y1-1][x1-1];
}
int main()
{
    int h,w;
    cin >> h >> w;
    int a[h+1][w+1];
    ll ans = 0;
    rep2(i,h) rep2(j,w) cin >> a[i][j];
    rep2(i,h) rep2(j,w) sum[i][j] = sum[i][j-1] + a[i][j];
    rep2(j,w) rep2(i,h) sum[i][j] += sum[i-1][j];
    //i番目の下、j番目の右に線を引く
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            if(i == h && j == w) continue;
            //縦横1本引くと、左上の領域と、その合計が確定するので、それと同じになるように線を引く
            //縦にひいて成り立つ組み合わせと横にひいて成り立つ組み合わせが両方引いて成り立つ組み合わせの候補
            vector<int> row; //行
            vector<int> line; //列
            bool ng = false;
            row.push_back(0);
            line.push_back(0);
            int s = calc_sum(1,1, j,i);
            rep2(k,h)
            {
                int tmp = calc_sum(1, row.back() + 1, j, k);
                if(tmp == s) row.push_back(k);
            }
            rep2(k, w)
            {
                int tmp = calc_sum(line.back() + 1, 1, k, i);
                if(tmp == s) line.push_back(k);
            }
            if(row.back() != h || line.back() != w) continue;
            //最後に線を引けない=国の端を決められない
            rep(k,row.size()-1)  //2
            {
                rep(l, line.size()-1) //1
                {
                    if(calc_sum(line[l]+1, row[k]+1, line[l+1], row[k+1]) != s)
                    {
                        ng = true;
                    }
                }
            }
            if(!ng) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}