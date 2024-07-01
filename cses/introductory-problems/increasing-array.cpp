/*
* problem: https://cses.fi/problemset/task/1094
*/

#include <bits/stdc++.h>
typedef long long ll;

int main(){

  ll n, temp;
  std::cin >>n;

  std::vector<ll> arr(n);

  for(ll i=0; i<n; i++){
    std::cin >> temp;

    arr[i] = temp;
  }

  ll count = 0;
  for(ll i=0; i < n - 1; i++){
    if(arr[i] > arr[i + 1]){
      count += arr[i] - arr[i + 1];
      arr[i+1] = arr[i];
    }
  }

  std::cout << count;
  return 0;
}
