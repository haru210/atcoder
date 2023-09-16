#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,n) for (int i = 1; i <= (int)(n); i++)
#define YesNo(bool) if(bool) cout << "Yes" << endl; else cout << "No" << endl 
#define YESNO(bool) if(bool) cout << "YES" << endl; else cout << "NO" << endl 

const int inf = 2147483647;
const long long l_inf = 9223372036854775807;
int main()
{
    map<string,int> s;
    s["tourist"] = 3858;
    s["ksun48"] = 3679;
    s["Benq"] = 3658;
    s["Um_nik"] = 3648;
    s["apiad"] = 3638;
    s["Stonefeang"] = 3630;
    s["ecnerwala"] = 3613;
    s["mnbvmar"] = 3555;
    s["newbiedmy"] = 3516;
    s["semiexp"] = 3481;
    string t;
    cin >> t;
    cout << s[t] << endl;
    return 0;
}