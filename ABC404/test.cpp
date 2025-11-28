#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define rep(i,n) for ( int i = 0; i < (n); ++i )
using namespace std;
using ll = long long;

int numberOfMatchedTile(const vector<vector<char>>& S, const vector<vector<char>>& T) {
  const int N = S.size();
  int res = 0;
  rep(i,N) {
    rep(j,N) {
      if ( S[i][j] == T[i][j] ) ++res;
    }
  }
  return res;
}

vector<vector<char>> getRotMatrix(const vector<vector<char>>& matrix, const bool clockwise) {
  int N = matrix.size();
  vector<vector<char>> rotMatrix(N, vector<char>(N));
  rep(i,N) {
    rep(j,N) {
      if ( clockwise ) {
        rotMatrix[i][j] = matrix[N-1-j][i];
      } else {
        rotMatrix[N-1-j][i] = matrix[i][j];
      }
    }
  }
  return rotMatrix;
}

int main() {
  int N;
  cin >> N;
  vector<vector<char>> S(N, vector<char>(N)), T(N, vector<char>(N));
  rep(i,N) rep(j,N) cin >> S[i][j];
  rep(i,N) rep(j,N) cin >> T[i][j];
  int numberOfRotation = 10;
  vector<vector<char>> rotMatrix_c(getRotMatrix(S, true));
  vector<vector<char>> rotMatrix_c2(getRotMatrix(getRotMatrix(S, true), true));
  vector<vector<char>> rotMatrix_c3(getRotMatrix(getRotMatrix(getRotMatrix(S, true), true), true));
  const int maxRotMatched = max({
    numberOfMatchedTile(S,T),
    numberOfMatchedTile(rotMatrix_c, T),
    numberOfMatchedTile(rotMatrix_c2, T),
    numberOfMatchedTile(rotMatrix_c3, T)
  });
  int numberOfReduceTile = 0;
  if ( maxRotMatched == numberOfMatchedTile(S,T) ) {
    numberOfRotation = min(numberOfRotation, 0);
    if ( numberOfRotation == 0 ) {
      numberOfReduceTile = N*N-numberOfMatchedTile(S,T);
    }
  }
  if ( maxRotMatched == numberOfMatchedTile(rotMatrix_c, T) ) {
    numberOfRotation = min(numberOfRotation, 1);
    if ( numberOfRotation == 1 ) {
      numberOfReduceTile = N*N-numberOfMatchedTile(rotMatrix_c,T);
    }
  }
  if ( maxRotMatched == numberOfMatchedTile(rotMatrix_c2,T) ) {
    numberOfRotation = min(numberOfRotation, 2);
    if ( numberOfRotation == 2 ) {
      numberOfReduceTile = N*N-numberOfMatchedTile(rotMatrix_c2,T);
    }
  }
  if ( maxRotMatched == numberOfMatchedTile(rotMatrix_c3,T) ) {
    numberOfRotation = min(numberOfRotation, 3);
    if ( numberOfRotation == 3 ) {
      numberOfReduceTile = N*N-numberOfMatchedTile(rotMatrix_c3,T);
    }
  }
  const int res = numberOfRotation+numberOfReduceTile;
  cout << res << endl;
  return 0;
}
