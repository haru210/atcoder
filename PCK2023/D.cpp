#include<bits/stdc++.h>
using namespace std;

int main()
{
    //辺の長さが同じかつ90度
    bool ok = true;
    int x[4], y[4];
    for(int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    int l_sq = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
    for(int i = 1; i < 4; i++)
    {
        int tmp;
        if(i == 3) tmp = (x[0] - x[3]) * (x[0] - x[3]) + (y[0] - y[3]) * (y[0] - y[3]);
        else tmp = (x[i+1] - x[i]) * (x[i+1] - x[i]) + (y[i+1] - y[i]) * (y[i+1] - y[i]);
        if(l_sq != tmp) ok = false;
    }
    int dx = x[1] - x[0];
    int dy = y[1] - y[0];
    bool left = true;
    bool right = true;
    for(int i = 1; i < 4; i++)
    {
        int tmp_x, tmp_y;
        if(i == 3)
        {
            tmp_x = x[0] - x[3];
            tmp_y = y[0] - y[3];
        }
        else
        {
            tmp_x = x[i+1] - x[i];
            tmp_y = y[i+1] - y[i];
        }
        if(dx != tmp_y || dy != -1 * tmp_x) {left = false;}
        dx = tmp_x;
        dy = tmp_y;
    }
    dx = x[1] - x[0];
    dy = y[1] - y[0];
    for(int i = 1; i < 4; i++)
    {
        int tmp_x, tmp_y;
        if(i == 3)
        {
            tmp_x = x[0] - x[3];
            tmp_y = y[0] - y[3];
        }
        else
        {
            tmp_x = x[i+1] - x[i];
            tmp_y = y[i+1] - y[i];
        }
        if(dx != -1 * tmp_y || dy != tmp_x) right = false;
        dx = tmp_x;
        dy = tmp_y;
    }
    if((!left) && (!right)) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}