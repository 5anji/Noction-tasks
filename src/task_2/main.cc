#include "main.hh"

int main() {
  char checker;
  Linked_List list;
  
  do {
    std::cout << "1 - Display the list" << std::endl;
    std::cout << "2 - Add node at the end" << std::endl;
    std::cout << "c - Clear Screen" << std::endl;
    std::cout << "q - Exit" << std::endl;

    std::cout << "Choose option >>> ";
    std::cin >> checker;

    checker = tolower(checker);

    switch (checker) {
    case '1':
      list.Print_List();
      break;
    case '2': {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list.Add_Node_End(temp);
      break;
    }
    case 'c':
      system("clear");
      break;
    case 'q':
      std::cout << "Exited." << std::endl;
      break;
    default:
      std::cout << "ERROR (no such option). Input again." << std::endl;
      break;
    }
  } while (checker != 'q');

  return 0;
}
