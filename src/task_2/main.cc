#include "main.hh"

int main() {
  char checker;
  Linked_List *list = new Linked_List;
  signal(SIGINT, signalHandler);
  
  do {
    std::cout << Bold(Blue("1")) << Orange(" - Display the list") << std::endl;
    std::cout << Bold(Blue("2")) << Orange(" - Add node at the end") << std::endl;
    std::cout << Bold(Blue("3")) << Orange(" - Add node at the start") << std::endl;
    std::cout << Bold(Blue("4")) << Orange(" - Add node at the ") + Bold(Orange("n")) + Orange(" position") << std::endl;
    std::cout << Bold(Blue("5")) << Orange(" - Delete node from the end") << std::endl;
    std::cout << Bold(Blue("6")) << Orange(" - Delete node from the start") << std::endl;
    std::cout << Bold(Blue("7")) << Orange(" - Delete node from the ") + Bold(Orange("n")) + Orange(" position") << std::endl;
    std::cout << Bold(Blue("8")) << Orange(" - Change data from the ") + Bold(Orange("n")) + Orange(" position") << std::endl;
    std::cout << Bold(Blue("d")) << Orange(" - Fully delete the list") << std::endl;
    std::cout << Bold(Blue("c")) << Orange(" - Clear Screen") << std::endl;
    std::cout << Bold(Blue("q")) << Orange(" - Exit") << std::endl;
    std::cout << std::endl;
    std::cout << Bold(Green("Choose option >>> "));
    std::cin >> checker;
    std::cout << std::endl;
    checker = tolower(checker);

    switch (checker) {
    case '1':
      list->Print_List();
      break;
    case '2': {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list->Add_Node_End(temp);
      break;
    }
    case '3': {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list->Add_Node_Start(temp);
      break;
    }
    case '4': {
      std::string temp;
      int position;
      std::cout << "Input data: ";
      std::cin >> temp;
      std::cout << "Input position of insertion: ";
      std::cin >> position;
      list->Add_Node_Position(temp, position);
      break;
    }
    case '5':
      list->Del_Node_End();
      break;
    case '6':
      list->Del_Node_Start();
      break;
    case '7': {
      int position;
      std::cout << "Input position of node to delete: ";
      std::cin >> position;
      list->Del_Node_Position(position);
      break;
    }
    case '8': {
      std::string temp;
      int position;
      std::cout << "Input position of the targeted data: ";
      std::cin >> position;
      std::cout << "Input new data: ";
      std::cin >> temp;
      list->Edit_Data(temp, position);
      break;
    }
    case 'd':
      list->Del_List();
      break;
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

  delete list;
  return 0;
}
