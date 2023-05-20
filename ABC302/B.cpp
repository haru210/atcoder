#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int search_width(pair<int ,int> x);
int search_horizontal(pair<int ,int> x);
int search_diagonal(pair<int ,int> x);

string s[100];
string T = "snuke";

int di[4] = {-1,-1,1,1};
int dj[4] = {-1,1,-1,1};

int h, w;

int main()
{
    pair <int, int> ans;
    int result = 0;
    cin >> h >> w;
    rep(i, h)
    {
        cin >> s[i];
    }
    rep(i, h)
    {
        rep(j, w)
        {
            ans.first = i;
            ans.second = j;
            if(s[i][j] == 's')
            {
                result = search_width(ans);
                if(result != 0)
                {
                    rep(k, 5)
                    {
                        cout << i + 1 << ' ' << j  + k* result + 1 << endl;
                    }
                }
                result = search_horizontal(ans);
                if(result != 0)
                {
                    rep(k, 5)
                    {
                        cout << i + k* result + 1 << ' ' << j + 1 << endl; 
                    }
                }
                result = search_diagonal(ans);
                if(result != -1)
                {
                    rep(k, 5)
                    {
                        cout << i + 1 + k*di[result] << ' ' << j + 1 + k * dj[result]<< endl;
                    }
                }
                result = -1;
            }
        }
    }
    return 0;
}

//return値1右側　-1左側
int search_width(pair<int ,int> x)
{
    bool key = true;
    rep(i, 5)
    {
        if(x.second - i < 0)
        {
            key = false;
            break;
        }
        if(s[x.first][x.second - i] != T[i]) key = false;
    }
    if(key) return -1;
    key = true;
    if((x.second + 4) < w)
    {
        rep(i, 5)
        {
            if(x.second + i >= w)
            {
                key = false;
                break;
            }
            if(s[x.first][x.second + i] != T[i]) key = false;
        }
        if(key) return  1;
    }
    return 0;
}

//return値 -1上向き　1下向き
int search_horizontal(pair<int ,int> x)
{
    bool key = true;
    if((x.first - 4) >= 0)
    {
        rep(i, 5)
        {
            if(s[x.first - i][x.second] != T[i]) key = false;
        }
        if(key) return -1;
    }
    key = true;
    if((x.first + 4) < h)
    {
        rep(i, 5)
        {
            if(s[x.first + i][x.second] != T[i]) key = false;
        }
        if(key) return 1;
    }
    return 0;
}

//return値　0左上 1右上 2左下 3右下
int search_diagonal(pair<int ,int> x)
{
    bool key = true;
    if(((x.first - 4) >= 0) && ((x.second - 4) >= 0))
    {
        rep(i, 5)
        {
            if(s[x.first - i][x.second - i] != T[i]) key = false;
        }
        if(key) return 0;
    }
    key = true;
    if(((x.first - 4) >= 0) && ((x.second  + 4) < w))
    {
        rep(i, 5)
        {
            if(s[x.first - i][x.second + i] != T[i]) key = false;
        }
        if(key) return 1;
    }
    key = true;
    if(((x.first + 4) < h && (x.second -4) >= 0))
    {
        rep(i, 5)
        {
            if(s[x.first + i][x.second - i] != T[i]) key = false;
        }
        if(key) return 2;
    }
    key = true;
    if(((x.first + 4) < h && (x.second  + 4) < w))
    {
        rep(i, 5)
        {
            if(s[x.first + i][x.second + i] != T[i]) key = false;
        }
        if(key) return 3;
    }
    return -1;
}

