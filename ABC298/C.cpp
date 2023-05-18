#include <bits/stdc++.h>
using namespace std;
using dic = vector<vector<int>>;

dic box(200000);
dic num(200000);

int main()
{
    int n, q;
    int kind;
    cin >> n >> q;
    int query[3];
    for(int i = 0; i < q; i++)
    {
        cin >> query[0];
        switch(query[0])
        {
            case 1:
            cin >> query[1] >> query[2];
            kind = 1;
            break;
            
            case 2:
            cin >> query[1];
            kind = 2;
            break;

            case 3:
            cin >> query[1];
            kind = 3;
            break;
        }
        if(kind == 1)
        {
            box[query[2]].push_back(query[1]);
            num[query[1]].push_back(query[2]);
        }
        if(kind == 2)
        {
            sort(box[query[1]].begin(), box[query[1]].end());
            for(int j = 0; j < box[query[1]].size(); j++)
            {
                cout << box[query[1]][j] << ' ';
            }
            cout << endl;
        }
        if(kind == 3)
        {
            sort(num[query[1]].begin(), num[query[1]].end());
            for(int k = 0; k < num[query[1]].size(); k++)
            {
                cout << num[query[1]][k] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}