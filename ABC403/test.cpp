#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i,n) for ( int i = 0; i < (n); ++i )
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> A(N);
  rep(i,N) cin >> A[i];
  map<int, int> cnts{};
  rep(i,N) {
    if ( A[i]%D != A[i] ) ++cnts[A[i]%D];
  }
  map<int, vector<int>> mp{};
  rep(i,N) {
    if ( cnts.count(A[i]%D) ) mp[A[i]%D].emplace_back(A[i]);
  }
  for ( auto& m : mp ) sort(m.second.begin(), m.second.end());
  int res = 0;
  for ( auto& m : mp ) {
    bool c = false;
    rep(i,m.second.size()-1) {
      if ( m.second[i+1] - m.second[i] == D ) {
        ++res;
        if ( c ) {
          --res;
          c = false;
        }
        c = true;
      } else {
        c = false;
      }
    }
  }
  cout << res << endl;
  return 0;
}
