#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    int i = 0;
    int end = 0;
    int check;
    int input;
    cin >> n;
    vector<int> a(n);
    rep(j, n)
    {
        cin >> a[j];
    }
    auto it = a.begin();
    it++;
    end = a.size();
    end--;
    while(true)
    {
        check = a[i] - a[i+1];
        if((abs(check)) != 1)
        {
            if(check > 0)
            {
                it = a.insert(it, (a[i] - 1));
                end++;
            }
            else
            {
                it = a.insert(it, (a[i] + 1));
                end++;
            }
        }
        it++;
        i++;
        if(i==end) break;
    }
    rep(j, (a.size()))
    {
       cout << a[j] << ' ';
    }
    cout << endl;
    return 0;
}