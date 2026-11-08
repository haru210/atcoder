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
    //各候補者について、第一希望の人を管理しておくと、その人が事態したときその候補者が分かり、その人の第二希望が誰か見ても、各投票者ごとに1回しかアクセスしない
    //この時新たに投票された全員にアクセスしても、その回数も全てのkで合計O(M)
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    vector<vector<int>> voters(n);
    int first_votes[n] = {};
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        voters[a[i]].push_back(i);
        first_votes[a[i]]++;
    }
    int winner = - -1;
    int wvotes = -1;
    int swinner = -1;
    int svotes = -1;
    rep(i, n)
    {
        if (first_votes[i] > wvotes)
        {
            swinner = winner;
            svotes = wvotes;
            winner = i;
            wvotes = first_votes[i];
        }
        else if (first_votes[i] > svotes)
        {
            swinner = i;
            svotes = first_votes[i];
        }
    }
    rep(i, n)
    {
        //当選者が辞退しない場合、当選し得るのは一位or増えた人
        //する場合、二位or増えた人
        set<int> may_win;
        if (winner != i)
        {
            may_win.insert(winner);
        }
        else
        {
            may_win.insert(swinner);
        }
        for (auto& voter: voters[i])
        {
            first_votes[b[voter]]++;
            may_win.insert(b[voter]);
        }
        int swinner = -1;
        int swvotes = -1;
        for (auto& c: may_win)
        {
            if (first_votes[c] > swvotes)
            {
                swinner = c;
                swvotes = first_votes[c];
            }
        }
        cout << swinner + 1 << endl;
        for (auto& voter : voters[i])
        {
            first_votes[b[voter]]--;
        }
    }
    return 0;
}
