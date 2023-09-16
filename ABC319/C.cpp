#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
bool opened[3][3] = {0};
int main()
{
    int c[3][3] = {0};
    int ok = 0;
    int ng = 0;
    rep(i,3) rep(j,3) cin >> c[i][j];
    int array[9] = {0,1,2,3,4,5,6,7,8};
    do
    {
        bool glad = true;
        rep(i,3) rep(j,3) opened[i][j] = false;
        rep(i,9){
            int x = array[i] % 3;
            int y = array[i] / 3;
            opened[y][x]= true;
            //がっかりしていないかチェック
            switch(y)
            {
                case 0:
                if((opened[y+1][x] && opened[y+2][x]) && (c[y+1][x] == c[y+2][x])) glad = false;
                break;

                case 1:
                if((opened[y-1][x] && opened[y+1][x]) && (c[y-1][x] == c[y+1][x])) glad = false;
                break;

                case 2:
                if((opened[y-1][x] && opened[y-2][x]) && (c[y-1][x] == c[y-2][x])) glad = false;
                break;
            }
            switch(x)
            {
                case 0:
                if((opened[y][x+1] && opened[y][x+2]) && (c[y][x+1] == c[y][x+2])) glad = false;
                break;

                case 1:
                if((opened[y][x-1] && opened[y][x+1]) && (c[y][x-1] == c[y][x+1])) glad = false;
                break;

                case 2:
                if((opened[y][x-1] && opened[y][x-2]) && (c[y][x-1] == c[y][x-2])) glad = false;
                break;
            }
            if(x == y)
            {
                if(x == 0) if((opened[y+1][x+1] && opened[y+2][x+2]) && (c[y+1][x+1] == c[y+2][x+2])) glad = false;
                if(x == 1) if((opened[y-1][x-1] && opened[y+1][x+1]) && (c[y-1][x-1] == c[y+1][x+1])) glad = false;
                if(x == 2) if((opened[y-1][x-1] && opened[y-2][x-2]) && (c[y-1][x-1] == c[y-2][x-2])) glad = false;
            }
            if(x + y == 2)
            {
                if(y == 0) if((opened[y+1][x-1] && opened[y+2][x-2]) && (c[y+1][x-1] == c[y+2][x-2])) glad = false;
                if(y == 1) if((opened[y-1][x+1] && opened[y+1][x-1]) && (c[y-1][x+1] == c[y+1][x-1])) glad = false;
                if(y == 2) if((opened[y-1][x+1] && opened[y-2][x+2]) && (c[y-1][x+1] == c[y-2][x+2])) glad = false;
            }
            if(!glad) break;
        }
        if(glad) ok++;
        if(!glad) ng++;
    }while(next_permutation(array,array+9));
    cout << fixed;
    cout << setprecision(15) <<(long double) ok / (long double)(ok + ng) << endl;
    return 0;
}

