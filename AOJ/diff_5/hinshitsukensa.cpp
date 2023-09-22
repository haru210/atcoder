#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    int a,b,c;
    int n;
    cin >> a >> b >> c >> n;
    int pass[a+b+c] = {0}; //0不明 1合格 -1不合格
    vector<tuple<int,int,int>> ok;
    vector<tuple<int,int,int>> ng;
    rep(i,n)
    {
        int tmp[3];
        bool result;
        cin >> tmp[0] >> tmp[1] >> tmp[2] >> result;
        tmp[0]--;
        tmp[1]--;
        tmp[2]--;
        if(result)
        {
            ok.push_back(make_tuple(tmp[0],tmp[1],tmp[2]));
            pass[tmp[0]] = 1;
            pass[tmp[1]] = 1;
            pass[tmp[2]] = 1;
        } 
        else ng.push_back(make_tuple(tmp[0],tmp[1],tmp[2]));
    } 
    rep(i,ng.size())
    {
        int bat,mot,cab;
        bat = get<0>(ng[i]);
        mot = get<1>(ng[i]);
        cab = get<2>(ng[i]);
        if(pass[bat] == 1 && pass[mot] ==1) pass[cab] = -1;
        if(pass[bat] == 1 && pass[cab] ==1) pass[mot] = -1;
        if(pass[mot] == 1 && pass[cab] ==1) pass[bat] = -1;
    }
    rep(i,a+b+c)
    {
        if(pass[i] == -1) cout << 0 << endl;
        else if(pass[i] == 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
}