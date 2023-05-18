#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    bool w = false;
    int firstw, secondw, trasure;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '|')
        {
            if(!w)
            {
                firstw = i;
                w = true;
            }
            else
            {
                secondw = i;
            }
        }
        else if(s[i] == '*')
        {
            trasure = i;
        }
    }
    if(firstw < trasure && trasure < secondw)
    {
        cout << "in\n";
    }
    else
    {
        cout << "out\n";
    }
    return 0;
}