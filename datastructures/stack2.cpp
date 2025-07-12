#include <iostream>
#include <vector>
using namespace std;

class Stack {
  vector<int> stackArr;
  int stop;
public:
  Stack () : stop(-1) {}

  void push(int val) {
    stackArr.push_back(val);
    stop++;
  }

  void pop() {
    if (stop>=0) {
      stop--;
      stackArr.pop_back();
    } else {
      cout << "error: cann't pop from empty stack!\n";
    }
  }

  bool empty() {
    return ( stop >= 0 && stackArr.size() != 0 );
  }

  int top() {
    if (stop >= 0) {
      return stackArr[stop];
    } else {
      cout << "Error: cann't return top of empty stack!\n";
    }
  }

  void print() {
    for (int i{0}; i<stackArr.size() ; i++ ) {
      cout << stackArr[i] << ',';
    }
    cout << '\n';
  }
};

int main() {
  Stack st1;
  st1.push(1);
  st1.push(2);
  st1.push(3);
  st1.push(4);
  st1.push(5);
  st1.print();
  st1.pop();
  st1.pop();
  st1.print();
  return 0;
}
