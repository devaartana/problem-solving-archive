/*
 * 3rd problem, 30 April 20204
 * link: https://codeforces.com/gym/104339/problem/A
 * lang: C++
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

  int val[3];

  string kings[5] = {"Barley", "Hops", "Malt"};

  int temp;
  for (int i = 0; i < 3; i++) {
    cin >> temp;

    val[i] = temp;
  }

  int max = 0;
  for (int i = 0; i < 3; i++) {
    cin >> temp;
    val[i] *= temp;

    if (val[i] > max)
      max = val[i];
  }

  for (int i = 0; i < 3; i++) {
    if (val[i] >= max) {
      cout << kings[i] << " ";
    }
  }

  return 0;
}
