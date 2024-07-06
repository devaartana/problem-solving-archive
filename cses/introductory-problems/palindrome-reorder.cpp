#include <iostream>
#include <vector>
typedef long long ll;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::string letter;
  std::cin >> letter;
  std::vector<ll> count(26, 0);

  ll j = 0, len = letter.length(), k = len - 1;
  for (char ch : letter) {
    count[ch - 'A']++;
  }

  ll odd_index = -1;
  std::vector<char> palindrome(len);
  for (ll i = 0; i < 26; i++) {
    if (count[i] & 1) {
      if (odd_index == -1) {
        odd_index = i;
      } else {
        std::cout << "NO SOLUTION";
        return 0;
      }
    }
    for (; count[i] > 1; count[i] -= 2) {
      palindrome[j++] = i + 'A';
      palindrome[k--] = i + 'A';
    }
  }

  if (count[odd_index] != -1)
    letter[len / 2] = odd_index + 'A';

  for (char c : palindrome) {
    std::cout << c;
  }
  return 0;
}
