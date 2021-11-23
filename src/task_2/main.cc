#include "main.hh"

int main() {
  char checker;
  Linked_List list;
  signal(SIGINT, signalHandler);
  
  do {
    std::cout << Bold(Blue("1")) << Orange(" - Display the list") << std::endl;
    std::cout << Bold(Blue("2")) << Orange(" - Add node at the end") << std::endl;
    std::cout << Bold(Blue("3")) << Orange(" - Add node at the start") << std::endl;
    std::cout << Bold(Blue("4")) << Orange(" - Add node at the ") + Bold(Orange("n")) + Orange(" position") << std::endl;
    std::cout << Bold(Blue("c")) << Orange(" - Clear Screen") << std::endl;
    std::cout << Bold(Blue("q")) << Orange(" - Exit") << std::endl;
    std::cout << std::endl;
    std::cout << Bold(Green("Choose option >>> "));
    std::cin >> checker;
    std::cout << std::endl;
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
    case '3': {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list.Add_Node_Start(temp);
      break;
    }
    case '4': {
      std::string temp;
      int position;
      std::cout << "Input data: ";
      std::cin >> temp;
      std::cout << "Input position of insertion: ";
      std::cin >> position;
      list.Add_Node_Position(temp, position);
      break;
    }
    case 'c':
      system("clear");
      break;
    case 'q':
      std::cout << "Exited." << std::endl;
      break;
    default:
      std::cout << Bold(Red("\vERROR (no such option). Input again.\v")) << std::endl;
      break;
    }
  } while (checker != 'q');

  return 0;
}
