/*
* problem: https://cses.fi/problemset/task/1069
*/

#include <bits/stdc++.h>

int main(){
  
  std::string sequence;
  std::cin >> sequence;

  char before = '\0';
  int count = 0, max = 0;
  for(int i=0; i<sequence.length(); i++){
    
    if(before == sequence[i]) count++;
    else {

      if(count > max) max = count;
      count = 1;
      before = sequence[i];
    }
  }

  if(count > max) max = count;

  std::cout << max;

  return 0;
}
