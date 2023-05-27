#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tmp;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        tmp = i %7;
        switch(tmp)
        {
            case 1:
            case 2:
            case 5:
            cout << "BASS\n";
            break;
            default:
            cout << "KICK\n";
            break;
        }
    }
    return 0;
}