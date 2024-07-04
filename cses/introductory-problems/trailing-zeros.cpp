#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  ll n, result = 0;
  std::cin >> n;
  
  ll temp = 5;
  while(temp <= n){
    result += n/temp;

    temp *= 5;
  }
  std::cout << result; 

  return 0;
}
