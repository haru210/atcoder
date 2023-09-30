#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define rep3(i,j,n) for(int i = (int)j; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    char myno[3][4][4];
    char myno_rotate[4][3][4][4];
    bool correct = false;
    rep(i,3) rep(j,4) rep(k,4) 
    {
        cin >> myno[i][j][k];
    }
    //回転 myno_rotateの1つめの添え字が向き　↑→↓←の順
    rep(i,3) rep(j,4) rep(k,4) myno_rotate[0][i][j][k] = myno[i][j][k];
    rep(i,3)
    {
        rep(j,4) rep(k,4)
        {
            myno_rotate[1][i][j][k] = myno[i][3 - k][j];
            myno_rotate[3][i][j][k] = myno[i][k][3 - j];
        }
        rep(j,4) rep(k,4)
        {
            myno_rotate[2][i][j][k] = myno_rotate[1][i][3-k][j];
        }
    }
    //ミノ1の位置、ミノ2の位置、ミノ3の位置、ミノ2の向き、ミノ3の向きを全探索
   rep3(a_i,-3,3) rep3(a_j,-3,3) rep(b_r,4) rep3(b_i,-3,3) rep3(b_j,-3,3)  rep(c_r,4)rep3(c_i,-3,3) rep3(c_j,-3,3)
    {
        if(correct) break;
        char ans[4][4];
        bool ok = true;
        bool ng = false;
        rep(i,4) rep(j,4) ans[i][j] = '.';
        //ミノ1
        //myno_rotateから#が外に出るか確認したい->myno_rotateから移動させるi+a_i
        //i,jが配列外参照しないように確認したい（#が外に出ていなければ.でいい）どこからi,jに来るか
        //が大事なので,i-a_i
        rep(i,4) rep(j,4)
        {
            if(ng) break;
            if((i+a_i < 0 || i + a_i > 3) && myno_rotate[0][0][i][j] == '#') {ng = true; break;}    
            if(i - a_i < 0 || i - a_i > 3) continue;
            if((j+a_j < 0 || j + a_j > 3) && myno_rotate[0][0][i][j] == '#') {ng = true; break;}       
            if(j - a_j < 0 || j - a_j > 3) continue;
            if(myno_rotate[0][0][i-a_i][j - a_j] == '#') 
            {
                if(ans[i][j] == '#')
                {
                    ng = true;
                    break;
                }
                else ans[i][j] = '#';
            }
        }
        //ミノ2
        rep(i,4) rep(j,4)
        {
            if(ng) break;
            if((i+b_i < 0 || i + b_i > 3) && myno_rotate[b_r][1][i][j] == '#') {ng = true; break;}   
            if(i - b_i < 0 || i - b_i > 3) continue; 
            if((j+b_j < 0 || j + b_j > 3) && myno_rotate[b_r][1][i][j] == '#') {ng = true; break;}    
            if(j - b_j < 0 || j - b_j > 3) continue;
            if(myno_rotate[b_r][1][i-b_i][j - b_j] == '#') 
            {
                if(ans[i][j] == '#')
                {
                    ng = true;
                    break;
                }
                else ans[i][j] = '#';
            }
        }
        //ミノ3
        rep(i,4) rep(j,4)
        {
            if(ng) break;
            if((i+c_i < 0 || i + c_i > 3) && myno_rotate[c_r][2][i][j] == '#'){ng = true; break;}    
            if(i - c_i < 0 || i - c_i > 3) continue;            
            if((j+c_j < 0 || j + c_j > 3) && myno_rotate[c_r][2][i][j] == '#') {ng = true; break;}    
            if(j - c_j < 0 || j - c_j > 3) continue; 
            if(myno_rotate[c_r][2][i-c_i][j-c_j] == '#') 
            {
                if(ans[i][j] == '#')
                {
                    ng = true;
                    break;
                }
                else ans[i][j] = '#';
            }
        }
        if(ng) continue;
        rep(i,4) rep(j,4)
        {
            if(ans[i][j] == '.') ok = false;
        }
        if(ok) correct = true;
    }
    YesNo(correct);
    return 0;
}
