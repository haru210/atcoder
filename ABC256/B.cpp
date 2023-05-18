#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    int score = 0;
    int a[100];
    bool runner[4] = {false};
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        runner[0] = true;
        for(int j = 3; j > -1; j--)
        {
            if(runner[j])
            {
                if((j + a[i]) >= 4)
                {
                    runner[j] = false;
                    score++;
                }
                else
                {
                    runner[j] = false;
                    runner[j + a[i]] = true;
                }
            }
        }
    }
   cout << score << endl;
    return 0;
}