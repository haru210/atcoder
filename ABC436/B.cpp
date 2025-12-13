#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;

int main()
{
    int n;
    cin >> n;
    int field[n][n];
    rep(i, n)
    {
        rep(j, n)
        {
            field[i][j] = -1;
        }
    }
    int backi = 0;
    int backj = (n - 1) / 2;
    int back_num = 1;
    field[0][(n - 1) / 2] = 1;
    rep(i, n * n - 1)
    {
        int numi = ((backi - 1) + n) % n;
        int numj = (backj + 1) % n;
        if(field[numi][numj] == -1)
        {
            field[numi][numj] = back_num + 1;
            back_num++;
            backi = numi;
            backj = numj;
        }
        else
        {
            numi = (backi + 1) % n;
            numj = backj;
            field[numi][numj] = back_num + 1;
            back_num++;
            backi = numi;
            backj = numj;
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            cout << field[i][j];
            if(j != n - 1) cout << ' ';
            else cout << endl; 
        }
    }
    return 0;
}