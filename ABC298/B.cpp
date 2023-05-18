#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int b[100][100];
int c[100][100];

int main()
{
    int n;
    int rollcount = 0;
    bool flag = false;
    bool first = false;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }

    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> b[i][j];
        }

    }
    while(true){
        flag = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((a[i][j] == 1) && b[i][j] == 0)
                {
                    flag = false;
                }
            }
        }
        if(first)
        {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                a[i][j] = c[i][j];
            }
        }

        }
        if(flag == true)
        {
            cout << "Yes\n";
            break;
        }
        else if(rollcount < 4)
        {
            
            for(int k = 0; k < n; k++)
            {
                for(int l = 0; l < n; l++)
                {
                    c[k][l] = a[n - (l + 1)][k];
                }
            }
            first = true;
            rollcount++;
        }
        else
        {
            cout << "No\n";
            break;
        }
    }
    return 0;
}