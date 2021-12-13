#include "colors.h"
#include "list.h"
#include "other.h"

int main() {
  char checker;
  Linked_List *list = new Linked_List;
  Linked_List *list_copy = new Linked_List;
  signal(SIGINT, signalHandler);

  do {
    display_menu(&checker);

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
    case '9': {
      list->Copy_List(*list_copy);
      break;
    }
    case '0': {
      list_copy->Print_List();
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
      std::cout << Bold(Red("\vERROR (no such option). Input again.\v"))
                << std::endl;
      break;
    }
  } while (checker != 'q');

  delete list;
  return 0;
}
