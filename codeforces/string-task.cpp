#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {

  string str;

  cin >> str;

  char temp;
  for (int i = 0; i < str.length(); i++) {

    temp = tolower(str[i]);

    if (!(temp == 'o' || temp == 'y' || temp == 'a' || temp == 'e' ||
          temp == 'u' || temp == 'i')) {
      cout << "." << temp;
    }
  }

  return 0;
}
