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
    int n,m;
    cin >> n >> m;
    int a[m];
    int score[n] = {0};
    string s[n];
    rep(i,m) cin >> a[i];
    rep(i,n) cin >> s[i];
    //現在のスコアを求めて、最大のスコアをインデックスといっしょに取っておく
    int max_score = 0;
    int max_index = -1;
    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j] == 'o') score[i]+= a[j];
        }
        score[i] += i+1;
        if(score[i] > max_score)
        {
            max_score = score[i];
            max_index = i;
        }
    }
    //解いてない問題を列挙して、それを降順にソートして、うえから超えるまで
    rep(i,n)
    {
        if(i == max_index)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            vector<int> unsolved;
            rep(j,m)
            {
                if(s[i][j] == 'x') unsolved.push_back(a[j]);
            }
            sort(unsolved.begin(),unsolved.end(),greater<int>());
            int cnt = 1;
            rep(j,unsolved.size())
            {
                score[i] += unsolved[j];
                if(score[i] > max_score)
                {
                    cout << cnt << endl;
                    break;
                }
                else cnt++;
            }
        }
    }
    return 0;
}