#include <iostream>

int add(int x, int y) {
  return x + y;
}

int substract(int x, int y) {
  return x - y;
}

int multiply(int x, int y) {
  return x * y;
}

int divide(int x, int y) {
  return x / y;
}

int func(int x, int y, int (*f)(int, int)) {
  return f(x, y);
}

int main() {
  int x = 10, y = 4;
  char op = '*';

  //int (*fun_ptr[])(int, int) = {add, substract, multiply, divide};

  // std::cout << "Input expression: ";
  // std::cin >> x >> op >> y;
  // std::cout << '(' << x << ' ' << op << ' ' << y << ')' << " = " << func(x, y, (*fun_ptr[2]) ) << std::endl;
  std::cout << func(10, 4, multiply);
  std::cout << func(10, 4, add);
  return 0;
}
