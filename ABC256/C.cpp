#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << " No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << " NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int h1,h2,h3,w1,w2,w3;
    int cnt = 0;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    int a_max = min(h1,w1);
    /*
    a b c
    d e f
    g h i
    */
   int c,f,g,h,i_1,i_2;
    for(int a = 1; a <= a_max - 2; a++)
    {
        for(int b = 1; b <= h1 - a - 1;b++)
        {
            for(int d = 1; d <= w1 - a - 1;d++)
            {
                for(int e = 1; e <= w2 - b - 1; e++)
                {
                    c = h1 - (a+b);
                    if(c < 1) continue;
                    f = h2 - (d+e);
                    if(f < 1) continue;
                    g = w1 - (a+d);
                    if(g < 1) continue;
                    h = w2 - (b+e);
                    if(h < 1) continue;
                    i_1 = h3 - (g+h);
                    if(i_1 < 1) continue;
                    i_2 = w3 - (c+f);
                    if(i_2 < 1) continue;
                    if(i_1 == i_2)
                    {
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}