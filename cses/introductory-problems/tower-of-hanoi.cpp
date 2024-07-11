#include <bits/stdc++.h>
typedef long long ll;

void changeState(std::vector<bool> &state, int target) {
  switch (target) {
  case 0:
    state[0] = true;
    state[1] = state[2] = false;
    break;
  case 1:
    state[1] = true;
    state[0] = state[2] = false;
    break;
  case 2:
    state[2] = true;
    state[0] = state[1] = false;
    break;
  default:
    break;
  }
}

bool oddOrEven(int a, int b) {
  if (a & 1) {
    return !(b & 1);
  }

  return b & 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::vector<std::stack<int>> st(3);
  std::vector<bool> stackState(3, false);
  int n;
  std::cin >> n;

  for (int i = n; i > 0; i--) {
    st[0].push(i);
  }

  int move = pow(2, n) - 1, smallest, smallestIndex, targetSt;
  std::cout << move << "\n";

  std::vector<int> mvPriority(2, -1);
  for (int i = 0; i < move; i++) {

    smallest = 17, smallestIndex = 0;
    for (int j = 0; j < 3; j++) {
      if (!st[j].empty() && st[j].top() < smallest && !stackState[j]) {
        smallest = st[j].top();
        smallestIndex = j;
      }
    }

    std::cout << smallestIndex + 1 << " ";

    if (!(n & 1)) {
      for (int j = 0; j < 3; j++) {
        if (st[j].empty() && mvPriority[1] == -1) {
          mvPriority[1] = j;
        }
        if (!st[j].empty() && mvPriority[0] == -1 &&
            (oddOrEven(smallest, st[j].top()) && smallest < st[j].top())) {
          mvPriority[0] = j;
        }
      }
    } else {
      for (int j = 0; j < 3; j++) {
        if (st[j].empty()) {
          mvPriority[1] = j;
        }
        if (!st[j].empty() &&
            (oddOrEven(smallest, st[j].top()) && smallest < st[j].top())) {
          mvPriority[0] = j;
        }
      }
    }

    for (int mv : mvPriority) {
      if (mv != -1) {
        targetSt = mv;
        break;
      }
    }
    std::cout << targetSt + 1 << "\n";
    changeState(stackState, targetSt);

    st[smallestIndex].pop();
    st[targetSt].push(smallest);
    mvPriority[0] = mvPriority[1] = -1;
  }

  return 0;
}
