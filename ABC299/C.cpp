#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int cnt = 0;
    int Llevel = 0;
    int Rlevel = 0;
    int level = 0;
    string s;
    bool start = false;
    cin >> n >> s;
    for(int i = 0; i < n; i++) //左から見ていく
    {
        if(!start && s[i] == '-')
        {
            start = true;
        }
        else if(start)
        {
            if(s[i] == 'o')
            {
                cnt++;
            }
            else
            {
                start = false;
                Llevel = max(Llevel, cnt);
                cnt = 0;
            }
        }
    }
    if(start)  //最後がoだった場合処理が終わらないので終了する
    {
        start = false;
        Llevel = max(Llevel, cnt);
        cnt = 0;
    }
    for(int i = n - 1; i > -1; i--) //右から見ていく
    {
        if(!start && s[i] == '-')
        {
            start = true;
        }
        else if(start)
        {
            if(s[i] == 'o')
            {
                cnt++;
            }
            else
            {
                Rlevel = max(Rlevel, cnt);
                cnt = 0;
            }
        }
    }
    if(start)  //最後がoだった場合処理が終わらないので終了する
    {
        Rlevel = max(Rlevel, cnt);
        cnt = 0;
    }
    level = max(Llevel,Rlevel);
  //  cout << Llevel << ' ' << Rlevel << endl;
    if(level == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << level << endl;
    }
    return 0;
}