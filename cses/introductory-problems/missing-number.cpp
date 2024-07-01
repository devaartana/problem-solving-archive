/*
* 2 July 2024
* problem: https://cses.fi/problemset/task/1083
*/

#include <bits/stdc++.h>

int main(){
  
  int n, temp;

  std::cin >> n;

  std::vector<bool> exist(n+1, false);
  
  for(int i=1 ;i < n;i++){
    std::cin >> temp;
    exist[temp] = true;
  }

  for(;n;n--){
    if(!exist[n]) std::cout << n;
  }
}

