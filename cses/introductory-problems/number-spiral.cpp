/*
* problem: https://cses.fi/problemset/task/1071
*/

#include <bits/stdc++.h>
typedef long long ll;

ll findVal(ll a, ll b, bool status){
  return a * a + ((a==b) ? -(b - 1) : a&1 ? (status) ? -(b - 1) : -(2 * a - 1 - b) : (status) ? -(2 * a - 1 - b) : -(b - 1));
}

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  ll n, row, col;
  std::cin >> n;

  for(int i=0; i<n; i++){
    std::cin >> row >> col;
    std::cout << findVal(std::max(row, col), std::min(row, col), col > row) << "\n";
  }

  return 0;
}
