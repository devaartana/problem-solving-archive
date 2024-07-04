#include <bits/stdc++.h>
typedef long long ll;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  ll n;
  std::cin >> n;

  ll result = 1;
  for(ll i=0; i < n; i++){
    result = (result * 2) % 1000000007; 
  }

  std::cout << result;
  return 0;
}
