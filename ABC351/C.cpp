#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int a[n];
    rep(i,n) cin >> a[i];
    vector<int> stack;
    rep(i,n)
    {
        stack.push_back(a[i]);
        while(true){
            if(stack.size() <= 1) break;
            int sl = stack.size() - 1;
            if(stack[sl] != stack[sl-1]) break;
            else
            {
                int nb = stack[sl] + 1;
                stack.pop_back();
                stack.pop_back();
                stack.push_back(nb);
            }
            
        }
    }
    cout << stack.size() << endl;
    return 0;
}