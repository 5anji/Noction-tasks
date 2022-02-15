#include "colors.h"
#include "list.h"
#include "other.h"

Node *head;
Node *end;

int main() {
  std::string checker;
  signal(SIGINT, signalHandler);
  init_map();

  do {
    display_menu(&checker);

    switch (str_val[checker]) {
    case str::option_1:
      Print_List();
      break;
    case str::option_2: {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      Add_Node_End(temp);
      break;
    }
    case str::option_3: {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      Add_Node_Start(temp);
      break;
    }
    case str::option_4: {
      std::string temp;
      int position;
      std::cout << "Input data: ";
      std::cin >> temp;
      std::cout << "Input position of insertion: ";
      std::cin >> position;
      Add_Node_Position(temp, position);
      break;
    }
    case str::option_5:
      Del_Node_End();
      break;
    case str::option_6:
      Del_Node_Start();
      break;
    case str::option_7: {
      int position;
      std::cout << "Input position of node to delete: ";
      std::cin >> position;
      Del_Node_Position(position);
      break;
    }
    case str::option_8: {
      std::string temp;
      int position;
      std::cout << "Input position of the targeted data: ";
      std::cin >> position;
      std::cout << "Input new data: ";
      std::cin >> temp;
      Edit_Data(temp, position);
      break;
    }
    case str::option_d:
      Del_List();
      break;
    case str::option_c:
      system("clear");
      break;
    case str::option_q:
      std::cout << "Exited." << std::endl;
      break;
    default:
      std::cout << Bold(Red("\vERROR (no such str::option). Input again.\v")) << std::endl;
      break;
    }
  } while (checker != "q");

  return 0;
}
