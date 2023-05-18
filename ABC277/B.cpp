#include <bits/stdc++.h>
using namespace std;

bool card[4][13] = {false};
int main()
{
    int n;
    int mark;
    int number;
    string s; 
    bool flag = false;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        if(s[0] == 'H')
        {
            mark = 0;
        }
        else if(s[0] == 'D')
        {
            mark = 1;
        }
        else if(s[0] == 'C')
        {
            mark = 2;
        }
        else if(s[0] == 'S')
        {
            mark = 3;
        }
        else
        {
            flag = true;
            break;
        }
        if(isdigit(s[1]))
        {
            
            number = s[1] - '0';
            if(number == 0)
            {
                flag = true;
                break;
            }
        }
        else
        {
            if(s[1] == 'A')
            {
                number = 1;
            }
            else if(s[1] == 'T')
            {
                number = 10;
            }
            else if(s[1] == 'J')
            {
                number = 11;
            }
            else if(s[1] == 'Q')
            {
                number = 12;
            }
            else if(s[1] == 'K')
            {
                number = 13;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if(!card[mark][number - 1])
        {
            card[mark][number - 1] = true;
        }
        else
        {
            flag = true;
        }
    }
    if(flag)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
    return 0;
}