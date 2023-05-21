#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//8方向に対応させるためsi,sjの変化値をテーブル化する
int di[8] = {-1,-1,-1,0,0,1,1,1};
int dj[8] = {-1,0,1,-1,1,-1,0,1}; 

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    string T = "snuke";
    rep(i, h) cin >> s[i];
    rep(si, h) rep(sj, w)
    {
        rep(direction, 8){ //8方向にループ        
        //開始点と違う位置の探索をしたいときは別変数に入れておく
        int i = si, j = sj; 
            rep(k, 5)      
            {
                if(i < 0 || i >= h || j < 0 || j >= w)  break;
                if(s[i][j] != T[k]) break;
                i += di[direction]; j += dj[direction];
                if(k == 4)
                {
                    //開始点を取っておくことでここで使える
                    i = si; 
                    j = sj;
                    rep(k, 5)
                    {
                        cout << i+1 << ' ' << j+1 << endl;
                        i += di[direction]; j += dj[direction];
                    }
                } 
            }
        }
    }
    return 0;
}