#include "exercises.hh"

int main(int argc, char const *argv[]) {
  float x, y, z;

  if (argc < 4) {
    std::cout << "Input x, y, z: ";
    std::cin >> x >> y >> z;
  } else {
    x = std::stoi(argv[1]);
    y = std::stoi(argv[2]);
    z = std::stoi(argv[3]);
  }
  
loop:
  int checker;
  std::cout << "Input exercise(int): ";
  std::cin >> checker;
  switch (checker) {
  case 1:
    ex_1(x, y, z);
    break;
  case 2:
    ex_2(x, y, z);
    break;
  case 3:
    ex_3(x, y, z);
    break;
  case 4:
    ex_4(x, y, z);
    break;
  case 5:
    ex_5(x, y, z);
    break;
  case 6:
    ex_6(x, y, z);
    break;
  case 7:
    ex_7(x, y, z);
    break;

  default:
    std::cout << "ERROR. Input again...\n*********************" << std::endl << std::endl;
    goto loop;
    break;
  }

  return 0;
}
