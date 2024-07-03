/*
* problem: https://cses.fi/problemset/task/1068 
*/

#include <bits/stdc++.h>
typedef long long ll;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  ll n;
  std::cin >> n;

  while(n != 1){
    if(n&1){
      std::cout << n << " ";
      n = n * 3 + 1;
    } else{
      std::cout << n << " ";
      n /= 2;
    }
  }

  std::cout << 1;

  return 0;
}
