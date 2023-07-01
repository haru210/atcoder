#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int a[200000],b[200000];
pair<double,int> rate[200000];
pair<double,int> ans[200000];
int result[200000];
int n;

void solver();
void solver2();
int main()
{
    cin >> n;
    srand((unsigned int)time(NULL));
    while(true){
    rep(i, n)
    {
        a[i] = rand();
        b[i] = rand();
    } 
   /* rep(i, n)
    {
        cin >> a[i] >> b[i];
    } */
    solver();
    solver2();
    rep(i,n)
    {
        if(rate[i].second != result[i])
        {
            cout << "now!\n";
            rep(i,n)
            {
                cout << a[i] <<' ' <<b[i] << endl;
            }
            return 0;
        }
    }
    cout << "not\n";
    }
}
void solver(){
    rep(i, n)
    {
        double tmp = (double)a[i] / ((double)a[i] + (double)b[i]);
        rate[i].first = tmp;
        rate[i].first *= (double)-1;
        rate[i].second = i + 1; //1-indexedに調整
    }
    rep(i, n)
    {
      //  cout << a[i] << ' ' << b[i] << endl;
     //   cout <<rate[i].first << endl;
    }
    sort(rate,rate + n);
    cout << endl;
}
void solver2()
{
    rep(i, n)
    {
        double tmp = (double)a[i] / ((double)a[i] + (double)b[i]);
        ans[i].first = tmp;
        ans[i].second = i + 1; //1-indexedに調整
    }
    rep(i,n)
    {
        double maxrate = 0;
        int maxnum = -1;
        rep(j,n)
        {
            if(maxrate < ans[j].first)
            {
                maxrate = ans[j].first;
                maxnum = j + 1;
            }
        }
        if(maxnum == 0) maxnum++;
        result[i] = maxnum;
        ans[maxnum - 1].first = 0;
    }
}