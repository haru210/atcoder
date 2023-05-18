#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s;
    string a;
    char ansA = 'a';
    int ansN = 0;
    for(int h = 0; h < 8; h++)
    {
        cin >> a;
        s.push_back(a);
    }
    for(int i = 0; i < 8; i++)
    {
        a = s[i];
        for(int j = 0; j < 8; j++)
        {
            if(a[j] == '*')
            {
                ansA += j;
                ansN = 8 - i;
            }
        }
    }
    cout << ansA << ansN << endl;
    return 0;
}