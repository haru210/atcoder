#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    int a, b;
    int tmp[5];
    int num;
    int sum = 0;
    cin >> n >> a >> b;
    rep(i, n + 1)
    {
        int j = 1;
        num = i;
        tmp[0] = num %10;
        while(num > 9){
            num /= 10;
            tmp[j] = num %10;
            j++;  
        }
        int tmp_sum = 0;
        for(int k = 0; k < j; k++)
        {
            tmp_sum += tmp[k];
        }
        if(tmp_sum >= a && tmp_sum <= b)
        {
            sum += i;
        }   
    }
    cout << sum << endl;
    return 0;
}