#include "other.h"
#include "colors.h"

void signalHandler(int position) {
  if (position == 2) {
    std::cout << std::endl
              << Bold(Red(":( Use q option instead of Ctrl+C")) << std::endl;
    exit(position);
  }
}

void display_menu(char *a) {
  std::cout << Bold(Blue("1")) << Orange(" - Display the list") << std::endl
            << Bold(Blue("2")) << Orange(" - Add node at the end") << std::endl
            << Bold(Blue("3")) << Orange(" - Add node at the start") << std::endl
            << Bold(Blue("4")) << Orange(" - Add node at the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue("5")) << Orange(" - Delete node from the end") << std::endl
            << Bold(Blue("6")) << Orange(" - Delete node from the start") << std::endl
            << Bold(Blue("7")) << Orange(" - Delete node from the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue("8")) << Orange(" - Change data from the ") + Bold(Orange("n")) + Orange(" position") << std::endl
            << Bold(Blue("d")) << Orange(" - Fully delete the list") << std::endl
            << Bold(Blue("c")) << Orange(" - Clear Screen") << std::endl
            << Bold(Blue("q")) << Orange(" - Exit") << std::endl
            << std::endl
            << Bold(Green("Choose option >>> "));
  std::cin >> *a;
  std::cout << std::endl;
  *a = tolower(*a);
}