#include <bits/stdc++.h>
using namespace std;

pair<int, int> card[200000];
int number[200000];
int main()
{
    int n, t;
    int j = 0;
    int maxnum;
    bool tcheck = false;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
    {
        cin >> card[i].first;
        if(card[i].first == t)
        {
            tcheck = true;
        }

    }
    for(int i = 0; i < n; i++)
    {
        cin >> card[i].second;
    }
    if(tcheck)
    {    
        for(int i = 0; i < n; i++)
        {
            if(card[i].first == t)
            {
                number[j] = card[i].second;
                j++;
            }
            sort(number, number + j, greater< int >());        
        }
        for(int i = 0; i < n; i++)
        {
            if(card[i].first == t && card[i].second == number[0])
            {
                cout << i + 1 << endl;
            }
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(card[i].first == card[0].first)
            {
                number[j] = card[i].second;
                j++;
            }
            sort(number, number + j, greater< int >());        
        }
        for(int i = 0; i < n; i++)
        {
            if(card[i].first == card[0].first && card[i].second == number[0])
            {
                cout << i + 1 << endl;
            }
        }
       
    }
    return 0;
}