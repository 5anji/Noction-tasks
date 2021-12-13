#include "colors.h"
#include "list.h"
#include "other.h"

int main() {
  std::string checker;
  Linked_List *list = new Linked_List;
  Linked_List *list_copy = new Linked_List;
  signal(SIGINT, signalHandler);
  init_map();

  do {
    display_menu(&checker);

    switch (str_val[checker]) {
    case option_1:
      list->Print_List();
      break;
    case option_2: {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list->Add_Node_End(temp);
      break;
    }
    case option_3: {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list->Add_Node_Start(temp);
      break;
    }
    case option_4: {
      std::string temp;
      int position;
      std::cout << "Input data: ";
      std::cin >> temp;
      std::cout << "Input position of insertion: ";
      std::cin >> position;
      list->Add_Node_Position(temp, position);
      break;
    }
    case option_5:
      list->Del_Node_End();
      break;
    case option_6:
      list->Del_Node_Start();
      break;
    case option_7: {
      int position;
      std::cout << "Input position of node to delete: ";
      std::cin >> position;
      list->Del_Node_Position(position);
      break;
    }
    case option_8: {
      std::string temp;
      int position;
      std::cout << "Input position of the targeted data: ";
      std::cin >> position;
      std::cout << "Input new data: ";
      std::cin >> temp;
      list->Edit_Data(temp, position);
      break;
    }
    case option_9: {
      list->Copy_List(*list_copy);
      break;
    }
    case option_10: {
      list_copy->Print_List();
      break;
    }
    case option_d:
      list->Del_List();
      break;
    case option_c:
      system("clear");
      break;
    case option_q:
      std::cout << "Exited." << std::endl;
      break;
    default:
      std::cout << Bold(Red("\vERROR (no such option). Input again.\v"))
                << std::endl;
      break;
    }
  } while (checker != "q");

  delete list;
  return 0;
}
