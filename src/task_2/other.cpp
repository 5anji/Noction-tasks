#include "other.h"
#include "colors.h"


std::map<std::string, str> str_val;

void signalHandler(int position) {
  if (position == 2) {
    std::cout << std::endl
              << Bold(Red(":( Use q option instead of Ctrl+C")) << std::endl;
    exit(position);
  }
}

void display_menu(std::string *a) {
  std::cout << Bold(Blue(" 1")) << Orange(" - Display the list") << std::endl
            << Bold(Blue(" 2")) << Orange(" - Add node at the end") << std::endl
            << Bold(Blue(" 3")) << Orange(" - Add node at the start") << std::endl
            << Bold(Blue(" 4")) << Orange(" - Add node at the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue(" 5")) << Orange(" - Delete node from the end") << std::endl
            << Bold(Blue(" 6")) << Orange(" - Delete node from the start") << std::endl
            << Bold(Blue(" 7")) << Orange(" - Delete node from the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue(" 8")) << Orange(" - Change data from the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue(" 9")) << Orange(" - Copy this list to the second") << std::endl
            << Bold(Blue("10")) << Orange(" - Display the next list") << std::endl
            << Bold(Blue(" d")) << Orange(" - Fully delete the list") << std::endl
            << Bold(Blue(" c")) << Orange(" - Clear Screen") << std::endl
            << Bold(Blue(" q")) << Orange(" - Exit") << std::endl
            << std::endl
            << Bold(Green("Choose option >>> "));
  std::cin >> *a;
  std::cout << std::endl;
  std::transform(a->begin(), a->end(), a->begin(), ::tolower);
}

void init_map() {
  str_val["1"] = option_1;
  str_val["2"] = option_2;
  str_val["3"] = option_3;
  str_val["4"] = option_4;
  str_val["5"] = option_5;
  str_val["6"] = option_6;
  str_val["7"] = option_7;
  str_val["8"] = option_8;
  str_val["9"] = option_9;
  str_val["10"] = option_10;
  str_val["d"] = option_d;
  str_val["c"] = option_c;
  str_val["q"] = option_q;
}