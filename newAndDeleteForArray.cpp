#include <iostream>
int main() {
  int x = 9;
  int *ar = new int[x];
  for (int i(0); i < x; i++) {
    ar[i] = 97 % (i + 4);
  }

  for (int i(0); i < x; i++) {
    std::cout << ar[i] << ',';
  }
  std::cout << '\n';

	delete [] ar;
  return 0;
}
