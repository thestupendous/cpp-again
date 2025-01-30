/*
 * std::optinal returns a nullptr if empty
 * or we can also check with has_value() method
 * thus, it can be checked for empty value when error condition is there
 */
#include <iostream>
#include <optional>
#include <climits> // for INT_MIN

using std::optional, std::cout;

std::optional<int> doIntegerDivision(int x, int y) {
  if (y == 0)
    return {};
  return (x / y);
}

int main() {
  std::optional<int> result1 = doIntegerDivision(20, 5);
  if (result1)
    cout << "Result 1 = " << *result1 << '\n';
  else
    cout << "Result1 failed!\n";

  optional<int> result2{doIntegerDivision(5, 0)};
  if (result2.has_value())
    cout << "Result 2 = " << result2.value_or(INT_MIN) << '\n';
  else
    cout << "Result2 failed!\n";
  return 0;
}
