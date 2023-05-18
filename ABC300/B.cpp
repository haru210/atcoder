#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

    char a[30][30];
    char b[30][30];
    char c[30][30];

int main()
{
    int h, w;
    bool aflag = false;
    bool bflag = false;
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < h; i++) //縦シフト
    {
        for(int j = 0; j < h; j++) //実際のシフト
        {
            for(int k = 0; k < w; k++)
            {
                if(j == 0)
                {
                    c[j][k] = a[h - 1][k];
                }
                else
                {
                    c[j][k] = a[j - 1][k];
                }
            }
        }
        aflag = true;    
        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)//あってる確認（あってたらbreakあってなかったら何もしない
            {
                a[j][k] = c[j][k];
                if(a[j][k] != b[j][k])
                {
                    aflag = false;
                }
            }
        }
        if(aflag) break; 
        //あってる確認（あってたらbreakあってなかったら何もしない
        for(int j = 0; j <= w; j++) //横シフト
        {
            for(int j = 0; j <= h; j++) //実際のシフト
            {
                for(int k = 0; k < w; k++)
                {
                    if(k == (w - 1))
                    {
                        c[j][k] = a[j][0];
                    }
                    else
                    {
                        c[j][k] = a[j][k + 1];
                    }
                }
            }
            bflag = true;    
            for(int j = 0; j < h; j++)
            {
                for(int k = 0; k < w; k++)//あってる確認（あってたらbreakあってなかったら何もしない
                {
                    a[j][k] = c[j][k];
                    if(a[j][k] != b[j][k])
                    {
                        bflag = false;
                    }
                }
            }
            if(bflag) break; 
        }
        if(bflag) break;
    }
    if(aflag || bflag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}