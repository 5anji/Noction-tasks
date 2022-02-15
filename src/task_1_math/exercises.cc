#include "exercises.hh"

float a, b;

void ex_1(float x, float y, float z) {
  a = (sqrtf(fabs(x - 1)) - cbrtf(fabsf(y))) /
      (1 + (powf(x, 2) / 2) + (powf(y, 2) / 4));
  b = x * (atanf(z) + powf(M_E, -(x + 3)));
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_2(float x, float y, float z) {
  a = (3 + powf(M_E, y - 1)) / (1 + powf(x, 2) * fabsf(y - tanf(z)));
  b = 1 + fabsf(y - x) + ((powf(y - x, 2)) / 2) + ((powf(fabsf(y - x), 3)) / 3);
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_3(float x, float y, float z) {
  a = (1 + y) * ((x + y)) / (powf(M_E, -x - 2)); // (x^2 + 4) can be simplified
  b = ((1 + cosf(y - 2)) * (2 + powf(sinf(z), 2))) / (powf(x, 4));
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_4(float x, float y, float z) {
  a = 0;
  b = 0;
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_5(float x, float y, float z) {
  a = 0;
  b = 0;
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_6(float x, float y, float z) {
  a = 0;
  b = 0;
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}
void ex_7(float x, float y, float z) {
  a = 0;
  b = 0;
  std::cout << "A = " << a << std::endl;
  std::cout << "B = " << b << std::endl;
}