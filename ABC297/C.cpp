#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    string s[110];
    string a;
    cin >> h >> w;
    for(int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if((s[i][j] == 'T') && (s[i][j + 1] == 'T'))
            {
                s[i][j] = 'P';
                s[i][j + 1] = 'C';
                j++;
            }
        }
    }
    for(int i = 0; i < h; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
}