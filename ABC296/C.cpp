#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    int a[200000];
    int num; //A_jのことで、探索したい数
    bool flag = false;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a + n);
    for(int i = 0; i < n; i++)
    {
        num = a[i] - x;
        if(binary_search(a, a + n, num))
        {
            flag = true;
        }
    }
    if(flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}